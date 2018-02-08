#include "Game.h"
#include <iostream>
using namespace std;

const char* menu = "\
o: set console output\n\
p: set number of players\n\
t: set number of turns\n\
r: run simulation\n\
d: set message delay\n\
l: set log filename\n\
g: set logging\n\
q: quit\n";

int main(){
	cout << "\nWelcome to Monopoly Statistics!\n";
	Game game;
	bool commentary = false;
	bool logging = true;
	unsigned int players = 6;
	unsigned int turns = 10000;
	unsigned int delay = 0;
	char command;
	char log_filename[256] = "MonopolyStats.log";
	do{
		cout << menu;
		cin >> command;
		switch(command){
			case 'o':
				cout << "commentary: true (1) or false (0): ";
				cin >> commentary;
				break;
			case 'p':
				cout << "Number of players: ";
				cin >> players;
				break;
			case 't':
				cout << "Number of turns: ";
				cin >> turns;
				break;
			case 'r':
				game.SetLogging(logging);
				game.SetLogFilename(log_filename);
				game.SetPrintDelay(delay);
				game.SetConsoleOutput(commentary);
				game.RunSimulation(players, turns);
				game.DisplayStats();
				break;
			case 'd':
				cout << "Delay (milliseconds): ";
				cin >> delay;
				break;
			case 'l':
				cout << "Log filename: ";
				cin >> log_filename;
				break;
			case 'g':
				cout << "logging: true (1) or false (0): ";
				cin >> logging;
				break;
			case 'q':
				break;
			default:
				cout << "Invalid command\n";
			break;
		}
	}while(command != 'q');

	cout << "Goodbye!\n\n";
	return 0;	
}