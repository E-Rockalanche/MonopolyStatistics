#include "Game.h"

Game::Game(){
}

void Game::RunSimulation(unsigned int players, unsigned long turns){
	log.Open(log_filename);
	this->players = players;
	Reset();
	unsigned long print_after_iterations = 10000;
	float progress = 0;
	cout << "Simulation begin\n";
	log << "Simulation begin\n";
	time_t start_time = time(NULL);

	for(unsigned long t = 0; t < turns; t++){
		if ((t > 0) && (t % print_after_iterations == 0)){
			progress = (float)(t*100)/(float)turns;
			cout << "Progress: " << progress << "\%\n";
		}

		for(unsigned int p = 0; p < player_list.size(); p++){
			Print("Player " + to_string(p+1) + "'s turn");
			PerformTurn(player_list[p]);
		}
	}

	time_t end_time = time(NULL);

	unsigned int total_time = end_time - start_time;

	string complete_message = "Simulation Complete. Took " + to_string(total_time) + " seconds\n";
	cout << complete_message;
	log << complete_message;
	log.Close();
}

void Game::SetLogFilename(const char* filename){
	log_filename = filename;
}

void Game::Print(string message) const{
	if (console_output){
		cout << message << '\n';
		Sleep(print_delay);
		//this_thread::sleep_for(chrono::milliseconds(print_delay));
	}
	if (do_logging){
		log << message << '\n';
	}
}

void Game::SetPrintDelay(unsigned int milliseconds){
	print_delay = milliseconds;
}

void Game::Reset(){
	Print("Reset");
	chance_cards.Reset(Chance::NUM_CARDS);
	community_chest_cards.Reset(CommunityChest::NUM_CARDS);
	player_list.resize(players);
	for(unsigned int i = 0; i < players; i++){
		player_list[i].Reset();
	}

	stats.Reset(GameBoard::REAL_NUM_TILES);
}

void Game::PerformTurn(Player& player){
	int doubles_count = 0;

	if (player.IsInJail()){
		if (player.HasGetOutOfJailFreeCard()){
			Print("\tUses get out of jail free card");
			//put one of the gojf cards into correct discard pile
			if (player.has_gojf_chance_card){
				player.has_gojf_chance_card = false;
				chance_cards.Discard(Chance::GET_OUT_OF_JAIL_FREE);
			}else if (player.has_gojf_community_chest_card){
				player.has_gojf_community_chest_card = false;
				community_chest_cards.Discard(CommunityChest::GET_OUT_OF_JAIL_FREE);
			}

			player.SetPosition(GameBoard::JUST_VISITING);
		}
	}

	do{
		int roll = dice.Roll();
		if (dice.WasDoubles()){
			Print("\tRolled doubles!");
			if (player.IsInJail()){
				Print("\tRolled doubles to get out of jail");
				player.SetPosition(GameBoard::JUST_VISITING);
			}

			doubles_count++;

			if (doubles_count == 3){
				Print("\tRolled doubles 3 times in a row. Going to jail");
				player.GoToJail();
				return;
			}
		}else if (player.IsInJail()){
			player.FailJailRoll();
			if (player.FailedMaxJailRolls()){
				Print("\tFailed 3 jail rolls, must pay to get out of jail");
				player.SetPosition(GameBoard::JUST_VISITING);
			}else{
				Print("\tStaying in jail");
				return;
			}
		}

		player.Move(roll);
		Print("\tMoved " + to_string(roll) + string(" spaces. Landed on ") + GameBoard::GetTileName(player.GetPosition()));

		stats.Count(player.GetPosition());
		PerformTileEffect(player);
	}while(dice.WasDoubles() && !player.IsInJail());
}

void Game::PerformTileEffect(Player& player){
	switch((GameBoard::Tile)player.GetPosition()){
		case GameBoard::GO_TO_JAIL:
			Print("\tGoing to jail");
			player.GoToJail();
			stats.Count(player.GetPosition());
			return;

		case GameBoard::CHANCE_1:
		case GameBoard::CHANCE_2:
		case GameBoard::CHANCE_3:
			PerformChanceCardEffect(chance_cards.Draw(), player);
			break;

		case GameBoard::COMMUNITY_CHEST_1:
		case GameBoard::COMMUNITY_CHEST_2:
		case GameBoard::COMMUNITY_CHEST_3:
			PerformCommunityChestCardEffect(community_chest_cards.Draw(), player);
			break;

		default:
			break;
	}
}

void Game::PerformChanceCardEffect(Chance::Card card, Player& player){
	int old_position = player.GetPosition();
	Print(string("\t") + Chance::GetCardName(card));

	switch(card){
		case Chance::ADVANCE_TO_GO:
			player.SetPosition(GameBoard::GO);
			stats.Count(player.GetPosition());
			break;

		case Chance::ADVANCE_TO_ILLINOIS_AVE:
			player.SetPosition(GameBoard::ILLINOIS_AVENUE);
			stats.Count(player.GetPosition());
			break;

		case Chance::ADVANCE_TO_ST_CHARLES_PLACE:
			player.SetPosition(GameBoard::ST_CHARLES_PLACE);
			stats.Count(player.GetPosition());
			break;

		case Chance::ADVANCE_TOKEN_TO_NEAREST_UTILITY:
			player.SetPosition(GameBoard::GetNearestUtility(player.GetPosition()));
			Print(string("Landed on ") + GameBoard::GetTileName(player.GetPosition()));
			stats.Count(player.GetPosition());
			break;

		case Chance::ADVANCE_TOKEN_TO_NEAREST_RAILROAD:
			player.SetPosition(GameBoard::GetNearestRailroad(player.GetPosition()));
			Print(string("Landed on ") + GameBoard::GetTileName(player.GetPosition()));
			stats.Count(player.GetPosition());
			break;

		case Chance::GET_OUT_OF_JAIL_FREE:
			player.has_gojf_chance_card = true;
			//return so that card is not immediately put into discard pile
			return;

		case Chance::GO_BACK_3_SPACES:
			player.Move(-3);
			Print(string("Landed on ") + GameBoard::GetTileName(player.GetPosition()));
			stats.Count(player.GetPosition());
			break;

		case Chance::GO_TO_JAIL:
			player.GoToJail();
			stats.Count(player.GetPosition());
			break;

		case Chance::TAKE_A_TRIP_TO_READING_RAILROAD:
			player.SetPosition(GameBoard::READING_RAILROAD);
			stats.Count(player.GetPosition());
			break;

		case Chance::TAKE_A_WALK_ON_THE_BOARDWALK:
			player.SetPosition(GameBoard::BOARDWALK);
			stats.Count(player.GetPosition());
			break;

		default:
			break;
	}

	chance_cards.Discard(card);

	if (player.GetPosition() != old_position){
			PerformTileEffect(player);
	}
}

void Game::PerformCommunityChestCardEffect(CommunityChest::Card card, Player& player){
	int old_position = player.GetPosition();
	Print(string("\t") + CommunityChest::GetCardName(card));

	switch(card){
		case CommunityChest::ADVANCE_TO_GO:
			player.SetPosition(GameBoard::GO);
			stats.Count(player.GetPosition());
			break;

		case CommunityChest::GET_OUT_OF_JAIL_FREE:
			player.has_gojf_community_chest_card = true;
			//return so that card is not immediately put into discard pile
			return;

		case CommunityChest::GO_TO_JAIL:
			player.GoToJail();
			stats.Count(player.GetPosition());
			break;

		default:
			break;
	}
	community_chest_cards.Discard(card);

	if (player.GetPosition() != old_position){
			PerformTileEffect(player);
	}
}
	
void Game::SetConsoleOutput(bool output){
	console_output = output;
}

void Game::DisplayStats() const{
	cout << "\n===========STATS===========\n";
	double total = stats.TotalCount();
	vector<Statistics::Tuple> sorted_array = stats.GetSortedTupleVector();
	float percent;
	for(unsigned int i = 0; i < sorted_array.size(); i++){
		percent = (double)(sorted_array[i].count*100) / total;
		cout << GameBoard::GetTileName(sorted_array[i].index) << ": " << percent << "\%\n";
	}
	cout << "===========================\n\n";
}
	
void Game::SetLogging(bool do_logging){
	this->do_logging = do_logging;
}