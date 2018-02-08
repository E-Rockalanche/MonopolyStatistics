#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "Player.h"
#include "CardStack.h"
#include "Chance.h"
#include "CommunityChest.h"
#include "Dice.h"
#include "Statistics.h"
#include "Logger.h"
#include <string>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <ctime>
using namespace std;

class Game{
private:
	unsigned int players;
	vector<Player> player_list;
	CardStack<Chance::Card> chance_cards;
	CardStack<CommunityChest::Card> community_chest_cards;
	Dice dice;
	bool console_output = false;
	bool do_logging = true;
	unsigned int print_delay = 0;
	const char* log_filename = "MonopolyStats.log";

	Statistics stats;

	void Reset();
	void PerformTurn(Player& player);
	void PerformTileEffect(Player& player);
	void PerformChanceCardEffect(Chance::Card card, Player& player);
	void PerformCommunityChestCardEffect(CommunityChest::Card card, Player& player);
	void Print(string message) const;

public:
	Game();
	void RunSimulation(unsigned int players, unsigned long turns);
	void DisplayStats() const;
	void SetConsoleOutput(bool output);
	void SetPrintDelay(unsigned int milliseconds);
	void SetLogFilename(const char* filename);
	void SetLogging(bool do_logging);
};

#endif