#include "GameBoard.h"

const char* GameBoard::tile_name[REAL_NUM_TILES] = {
	"GO",
	"Mediteranean Avenue",
	"Community Chest 1",
	"Baltic Avenue",
	"Income Tax",
	"Reading Railroad",
	"Oriental Avenue",
	"Chance 1",
	"Vermont Avenue",
	"Connecticut Avenue",

	"Just Visiting",
	"St. Charles Place",
	"Electric Company",
	"States Avenue",
	"Virginia Avenue",
	"Pensylvania Railroad",
	"St. James Place",
	"Community Chest 2",
	"Tennessee Avenue",
	"New York Avenue",

	"Free Parking",
	"Kentucky Avenue",
	"Chance 2",
	"Indiana Avenue",
	"Illinois Avenue",
	"B. & O. Railroad",
	"Atlantic Avenue",
	"Ventnor Avenue",
	"Water Works",
	"Marvin Gardens",

	"GO TO JAIL",
	"Pacific Avenue",
	"North Carolina Avenue",
	"Community Chest 3",
	"Pensylvania Avenue",
	"Short Line",
	"Chance 3",
	"Park Place",
	"Luxury Tax",
	"Boardwalk",

	"In Jail",
};

const char* GameBoard::tile_group_names[NUM_TILE_GROUPS] = {
	"Other",
	"Chance",
	"Community Chest",
	"Brown",
	"Light Blue",
	"Pink",
	"Orange",
	"Red",
	"Yellow",
	"Green",
	"Blue",
	"Railroad",
	"Utility"
};

const int GameBoard::tile_groups[REAL_NUM_TILES] = {
	OTHER,
	BROWN,
	COMMUNITY_CHEST,
	BROWN,
	OTHER,
	RAILROAD,
	L_BLUE,
	CHANCE,
	L_BLUE,
	L_BLUE,

	JUST_VISITING,
	PINK,
	UTILITY,
	PINK,
	PINK,
	RAILROAD,
	ORANGE,
	COMMUNITY_CHEST,
	ORANGE,
	ORANGE,

	OTHER,
	RED,
	CHANCE,
	RED,
	RED,
	RAILROAD,
	YELLOW,
	YELLOW,
	UTILITY,
	YELLOW,

	OTHER,
	GREEN,
	GREEN,
	COMMUNITY_CHEST,
	GREEN,
	RAILROAD,
	CHANCE,
	BLUE,
	OTHER,
	BLUE,

	OTHER
};

const char* GameBoard::GetTileName(int position) {
	return tile_name[position];
}

const char* GameBoard::GetTileGroupName(int index) {
	return tile_group_names[index];
}

int GameBoard::GetTileGroup(int position) {
	return tile_groups[position];
}

GameBoard::Tile GameBoard::GetNearestRailroad(int position) {
	if ((position < (int)GameBoard::READING_RAILROAD) || (position > (int)GameBoard::SHORT_LINE)) {
		return GameBoard::READING_RAILROAD;
	} else if (position < (int)GameBoard::PENSYLVANIA_RAILROAD) {
		return GameBoard::PENSYLVANIA_AVENUE;
	} else if (position < (int)GameBoard::B_AND_O_RAILROAD) {
		return GameBoard::B_AND_O_RAILROAD;
	} else {
		return GameBoard::SHORT_LINE;
	}
}

GameBoard::Tile GameBoard::GetNearestUtility(int position) {
	if ((position < (int)GameBoard::ELECTRIC_COMPANY) || (position > (int)GameBoard::WATER_WORKS)) {
		return GameBoard::ELECTRIC_COMPANY;
	} else {
		return GameBoard::WATER_WORKS;
	}
}