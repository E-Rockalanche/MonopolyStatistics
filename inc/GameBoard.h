class GameBoard{
public:
	enum Tile{
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

		IN_JAIL,

		NUM_TILES = 40,
		REAL_NUM_TILES = 41,
	};

	enum TileGroup {
		OTHER,
		CHANCE,
		COMMUNITY_CHEST,

		BROWN,
		L_BLUE,
		PINK,
		ORANGE,
		RED,
		YELLOW,
		GREEN,
		BLUE,

		RAILROAD,
		UTILITY,

		NUM_TILE_GROUPS
	};

	static const char* tile_name[REAL_NUM_TILES];
	static const int tile_groups[REAL_NUM_TILES];
	static const char* tile_group_names[NUM_TILE_GROUPS];
	
	static const char* GetTileName(int position);
	static Tile GetNearestRailroad(int position);
	static Tile GetNearestUtility(int position);
	static int GetTileGroup(int position);
	static const char* GetTileGroupName(int index);
};