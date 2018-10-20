#include "Chance.h"

const char* Chance::card_name[Chance::NUM_CARDS] = {
	"Advance to go",
	"Advance to Illinois Ave",
	"Advance to St. Charles Place",
	"Advance token to nearest utility",
	"Advance token to nearest railroad",
	"Bank pays you dividend of $50",
	"Get out of jail free",
	"Go back 3 spaces",
	"Go to jail",
	"Make general repairs on all your preoperty",
	"Pay poor tax",
	"Take a trip to reading railroad",
	"Take a walk on the boardwalk",
	"You have been elected chairman of the board",
	"Your building loan matures",
	"You have won a crossword competition"
};

const char* Chance::GetCardName(Chance::Card card){
	return card_name[(unsigned int)card];
}