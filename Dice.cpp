#include "Dice.h"
#include "rng.h"

int Dice::Roll(){
	for(int i = 0; i < 2; i++){
		die[i] = rng.IRandom(6) + 1;
	}
	return die[0] + die[1];
}

bool Dice::WasDoubles(){
	return die[0] == die[1];
}