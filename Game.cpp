#include "Game.h"

void Game::RunSimulation(int players, int turns){
	this->players = players;
	this->turns = turns;
	Reset();

	for(int t = 0; t < turns; t++){
		for(int p = 0; p < players; p++){
			PerformTurn(player_list[p]);
		}
	}
}

void Game::Reset(){
	chance_cards.Reset(Chance::NUM_CARDS);
	chance_cards.Reset(CommunityChest::NUM_CARDS);
	player_list.resize(players);
	for(int i = 0; i < players; i++){
		player_list[i].Reset();
	}
}

void Game::PerformTurn(Player& player){
	int doubles_count = 0;

	if (player.IsInJail()){
		if (player.HasGetOutOfJailFreeCard()){
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
			if (player.IsInJail()){
				player.SetPosition(GameBoard::JUST_VISITING);
			}

			doubles_count++;

			if (doubles_count == 3){
				PutPlayerInJail(player);
				return;
			}
		}else if (player.IsInJail()){
			player.FailJailRoll();
			if (player.FailedMaxJailRolls()){
				player.SetPosition(GameBoard::JUST_VISITING);
			}else{
				return;
			}
		}

		player.Move(roll);
		PerformTileEffect(player);
	}while(dice.WasDoubles() && !player.IsInJail());
}

void Game::PerformTileEffect(Player& player){
	switch((GameBoard::Tile)player.GetPosition()){
		case GameBoard::GO_TO_JAIL:
			PutPlayerInJail(player);
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

void Game::PerformChanceCardEffect(Chance card, Player& player){
	int old_position = player.GetPosition();
	switch(card){
		case Chance::ADVANCE_TO_GO:
			player.SetPosition(GameBoard::GO);
			break;

		case Chance::ADVANCE_TO_ILLINOIS_AVE:
			player.SetPosition(GameBoard::ILLINOIS_AVENUE);
			break;

		case Chance::ADVANCE_TO_ST_CHARLES_PLACE:
			player.SetPosition(GameBoard::ST_CHARLES_PLACE);
			break;

		case Chance::ADVANCE_TOKEN_TO_NEAREST_UTILITY:
			player.SetPosition(GameBoard::GetNearestUtility(player.GetPosition()));
			break;

		case Chance::ADVANCE_TOKEN_TO_NEAREST_RAILROAD:
			player.SetPosition(GameBoard::GetNearestRailroad(player.GetPosition()));
			break;

		case Chance::GET_OUT_OF_JAIL_FREE:
			player.has_gojf_chance_card = true;
			//return so that card is not immediately put into discard pile
			return;

		case Chance::GO_BACK_3_SPACES:
			player.Move(-3);
			break;

		case Chance::GO_TO_JAIL:
			player.GoToJail();
			break;

		case Chance::TAKE_A_TRIP_TO_READING_RAILROAD:
			player.SetPosition(GameBoard::READING_RAILROAD);
			break;

		case Chance::TAKE_A_WALK_ON_THE_BOARDWALK:
			player.SetPosition(GameBoard::BOARDWALK);
			break;

		default:
			break;
	}

	chance_cards.Discard(card);

	if (player.GetPosition() != old_position){
			PerformTileEffect(player);
	}
}

void Game::PerformCommunityChestCardEffect(Chance card, Player& player){
	int old_position = player.GetPosition();

	switch(card){
		case CommunityChest::ADVANCE_TO_GO:
			player.SetPosition(GameBoard::GO);
			break;

		case CommunityChest::GET_OUT_OF_JAIL_FREE:
			player.has_gojf_community_chest_card = true;
			//return so that card is not immediately put into discard pile
			return;

		case CommunityChest::GO_TO_JAIL:
			player.GoToJail();
			break;

		default:
			break;
	}
	community_chest_cards.Discard(card);

	if (player.GetPosition() != old_position){
			PerformTileEffect(player);
	}
}