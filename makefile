CC = g++ -Wall -Wextra -c -std=c++11

MonopolyStats:	main.o Game.o Statistics.o GameBoard.o Player.o Dice.o Chance.o CommunityChest.o Logger.o rng.o
	g++ -static main.o Game.o Statistics.o GameBoard.o Player.o Dice.o Chance.o CommunityChest.o Logger.o rng.o -o MonopolyStats.exe

main.o:	main.cpp
	$(CC) main.cpp -o main.o

Game.o:	Game.cpp
	$(CC) Game.cpp -o Game.o

Statistics.o:	Statistics.cpp
	$(CC) Statistics.cpp -o Statistics.o

Player.o:	Player.cpp
	$(CC) Player.cpp -o Player.o

GameBoard.o:	GameBoard.cpp
	$(CC) GameBoard.cpp -o GameBoard.o

Dice.o:	Dice.cpp
	$(CC) Dice.cpp -o Dice.o

Chance.o: Chance.cpp
	$(CC) Chance.cpp -o Chance.o

CommunityChest.o: CommunityChest.cpp
	$(CC) CommunityChest.cpp -o CommunityChest.o

Logger.o:	Logger.cpp
	$(CC) Logger.cpp -o Logger.o

rng.o:	rng.cpp
	$(CC) rng.cpp -o rng.o

clean:
	del *.o