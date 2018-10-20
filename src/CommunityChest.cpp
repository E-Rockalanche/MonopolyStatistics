#include "CommunityChest.h"

const char* CommunityChest::card_name[CommunityChest::NUM_CARDS] = {
	"Advance to go",
	"Bank error in your favour",
	"Doctor's fee",
	"From sale of stock you get $50",
	"Get out of jail free",
	"Go to jail",
	"Grand opera night",
	"Holidy fund matures",
	"Income tax refund",
	"It is your birthday",
	"Life insurance matures",
	"Pay hospital fees",
	"Pay school fees",
	"Receive $25 consultancy fee",
	"You are assessed for street repair",
	"You have won second prize in a beauty contest",
	"You inherit $100"
};

const char* CommunityChest::GetCardName(CommunityChest::Card card){
	return card_name[(unsigned int)card];
}