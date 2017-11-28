#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "Player.h"
#include "CardStack.h"
#include "Chance.h"
#include "CommunityChest.h"

class Game{
private:
	int tile_land_count[NUM_TILES];
	vector<Player> player_list;
	CardStack<Chance::Card> chance_cards;
	CardStack<CommunityChest::Card> community_chest_cards;
	Dice dice;

	void Reset();
	void PerformTurn(Player& player);
	void PerformTileEffect(Player& player);
	void PerformChanceCardEffect(Chance::Card card, Player& player);
	void PerformCommunityChestCardEffect(CommunityChest::Card card, Player& player);

public:
	void RunSimulation(int players, int turns);
};

#endif