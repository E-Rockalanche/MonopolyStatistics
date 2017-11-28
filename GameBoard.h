class GameBoard{
public:
	enum TILE{
		GO,
		MEDITERANEAN_AVENUE,
		COMMUNITY_CHEST_1,
		BALTIC_AVENUE,
		INCOME_TAX,
		READING_RAILROAD,
		ORIENTAL_AVENUE,
		CHANCE_1,
		VERMONT_AVENUE,
		CONNECTICUT_AVENUE,
		JUST_VISITING,
		ST_CHARLES_PLACE,
		ELECTRIC_COMPANY,
		STATES_AVENUE,
		VIRGINIA_AVENUE,
		PENSYLVANIA_RAILROAD,
		ST_JAMES_PLACE,
		COMMUNITY_CHEST_2,
		TENESSEE_AVENUE,
		NEY_YORK_AVENUE,
		FREE_PARKING,
		KENTUCKY_AVENUE,
		CHANCE_2,
		INDIANA_AVENUE,
		ILLINOIS_AVENUE,
		B_AND_O_RAILROAD,
		ATLANTIC_AVENUE,
		VENTNOR_AVENUE,
		WATER_WORKS,
		MARVIN_GARDENS,
		GO_TO_JAIL,
		PACIFIC_AVENUE,
		NORTH_CAROLINA_AVENUE,
		COMMUNITY_CHEST_3,
		PENSYLVANIA_AVENUE,
		SHORT_LINE,
		CHANCE_3,
		PARK_PLACE,
		LUXURY_TAX,
		BOARDWALK,

		NUM_TILES,

		IN_JAIL,
	}
	static const char** tile_name = {
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
		"Ney York Avenue",
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
		"Boardwalk";
		"Number of tiles",
		"In Jail",
	};
	
	static const char* GetTileName(int position);
	static Tile GetNearestRailroad(int position);
	static Tile GetNearestUtility(int position);
};