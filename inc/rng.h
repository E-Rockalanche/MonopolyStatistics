#ifndef RNG_H_ERIC_ROBERTS
#define RNG_H_ERIC_ROBERTS

typedef unsigned int uint;

class RNG{
private:
	uint a;
	uint b;
	uint c;
	uint d;
	uint seed;

	uint Value();

public:
	//create rng object with time seed
	RNG();
	//create rng object with given seed
	RNG(uint s);

	//get current seed
	uint GetSeed();

	//set seed
	void SetSeed(uint s);

	//return value in range [0,  n)
	float Random(float n);
	//return value in range [low, high)
	float RandomRange(float low, float high);
	//return if percent chance succeeded
	bool Chance(float percent);

	//return value in range [0, n-1]
	uint IRandom(uint n);
	//return value in range [low, high]
	int IRandomRange(int low, int high);
	//return if percent chance succeeded
	bool Chance(int percent);
};

extern RNG rng;

#endif