#include "GameBoard.h"

const char* GameBoard::GetTileName(int position){
	return tile_name[position];
}

static GameBoard::Tile GameBoard::GetNearestRailroad(int position){
	if ((position < (int)GameBoard::READING_RAILROAD) || (position > (int)GameBoard::SHORT_LINE)){
		return GameBoard::READING_RAILROAD;
	}else if (position < (int)GameBoard::PENSYLVANIA_RAILROAD){
		return GameBoard::PENSYLVANIA_AVENUE;
	}else if (position < (int)GameBoard::B_AND_O_RAILROAD){
		return GameBoard::B_AND_O_RAILROAD;
	}else{
		return GameBoard::SHORT_LINE;
	}
}

static GameBoard::Tile GameBoard::GetNearestUtility(int position){
	if ((position < (int)GameBoard::ELECTRIC_COMPANY) || (position > (int)GameBoard::WATER_WORKS)){
		return GameBoard::ELECTRIC_COMPANY;
	}else{
		return GameBoard::WATER_WORKS;
	}
}