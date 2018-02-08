#ifndef CARD_STACK_H
#define CARD_STACK_H

#include <iostream>
#include <vector>
#include "rng.h"
using namespace std;

//#define dout(N) cout << "Debug: " << __FILE__ << " (" << __LINE__ << "): " << N << '\n'
#define dout(N)

template <class T>
class CardStack{
private:
	vector<T> deck;
	vector<T> discard_pile;

public:
	void Reset(unsigned int num_cards);
	T Draw();
	void Discard(T card);
	void Shuffle();
};

template <class T>
void CardStack<T>::Reset(unsigned int num_cards){
	dout("Reset(" << num_cards << ")");

	deck.resize(num_cards, (T)0);

	dout("deck.size after resize = " << deck.size());

	discard_pile.clear();
	for(unsigned int i = 0; i < deck.size(); i++){
		deck[i] = (T)i;
	}

	dout("deck.size after initial values = " << deck.size());

	Shuffle();

	dout("deck.size after shuffle = " << deck.size());
}

template <class T>
T CardStack<T>::Draw(){
	dout("Draw()");
	if (deck.size() == 0){
		Shuffle();
	}

	if (deck.size() == 0){
		cout << "***** ERROR in file " << __FILE__ << ", line " << __LINE__ << ": deck size is 0 after shuffle *****\n";
	}

	T card = deck.back();
	deck.pop_back();

	return card;
}

template <class T>
void CardStack<T>::Discard(T card){
	dout("Discard(" << card << ")");
	discard_pile.push_back(card);
}

template <class T>
void CardStack<T>::Shuffle(){
	dout("Shuffling " << discard_pile.size() << " cards back into deck of size " << deck.size());

	while(discard_pile.size() > 0){
		deck.push_back(discard_pile.back());
		discard_pile.pop_back();
	}

	for(unsigned int i = 0; i < deck.size(); i++){
		unsigned int j = rng.IRandom(deck.size());
		if (j >= deck.size()){
			cout << "***** ERROR in file " << __FILE__ << ", line " << __LINE__ << ": trying to shuffle card out of deck size *****\n";
		}else{
			T temp = deck[i];
			deck[i] = deck[j];
			deck[j] = temp;
		}
	}

	dout("Shuffle complete");
}

#undef dout

#endif