#include "rng.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

#define ROT_RNG(x,y) (((x) << (y)) | ((x) >> (32 - (y))))
#define CLAMP_RNG(x, low, high) ((x) < (low) ? (low) : ((x) > (high) ? (high) : (x)))
#define RANDOM_MAX_RNG 0xFFFFFFFF
#define MAGIC_NUMBER_RNG 0x19950801
/*
0xF1EA5EED
0xDEAD9001
0x19950801
0xDEADDEAD
*/

//#define dout(N) cout << "Debug: " << __FILE__ << " (" << __LINE__ << "): " << N << '\n'
#define dout(N)

//private:

//returns a pseudo-random unsigned integer
uint RNG::Value(){
	uint temp = a - ROT_RNG(b, 27);
	a = b ^ ROT_RNG(c, 17);
	b = c + d;
	c = d + temp;
	d = a + temp;
	return d;
}


//initializes object and sets seed to time
RNG::RNG(){
	SetSeed(0);
}

//initializes object and sets seed to given uint
RNG::RNG(uint s){
	SetSeed(s);
}

//initializes state with new seed
void RNG::SetSeed(uint s){
	dout("SetSeed(" << s << ")");
	seed = s;
	if (seed == 0){
		seed = (unsigned long) time(NULL) - 1352700000;
	}
	a = MAGIC_NUMBER_RNG;
	b = c = d = seed;
	for(int i = 0; i < 20; ++i){
		Value();
	}
}

//return a value in range [0, n)
float RNG::Random(float n){
	if (n < 0){
		return 0;
	}

	float div = RANDOM_MAX_RNG / n;
	float r;

	do{
		r = Value() / div;
	}while(r >= n);

	return r;
}

//returns a value in range [low, high]
float RNG::RandomRange(float low, float high){
	if (high < low){
		return low;
	}
	return Random(high - low) + low;
}

//returns a value in range [0, n-1]
uint RNG::IRandom(uint n){
	dout("IRandom(" << n << ")");
	uint div = RANDOM_MAX_RNG / n;
	uint r;

	do{
		r = Value() / div;
	}while(r >= n);

	return r;
}

//returns a value in range [low, high]
int RNG::IRandomRange(int low, int high){
	if (high < low){
		return low;
	}
	return IRandom(high - low + 1) + low;
}

//returns if percent chance succeeded
bool RNG::Chance(float percent){
	return (Random(100.0) < CLAMP_RNG(percent, 0.0, 100.0));
}

//returns if percent chance succeeded
bool RNG::Chance(int percent){
	return ((int)IRandom(100) < CLAMP_RNG(percent, 0, 100));
}

//return current seed
uint RNG::GetSeed(){
	return seed;
}

#undef ROT_RNG
#undef CLAMP_RNG
#undef MAGIC_NUMBER_RNG
#undef RANDOM_MAX_RNG

RNG rng;