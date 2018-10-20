#ifndef DICE_H
#define DICE_H

class Dice{
private:
	int die[2];

public:
	int Roll();
	bool WasDoubles();
};

#endif