#ifndef CARD_STACK_H
#define CARD_STACK_H

#include <vector>
#include "rng.h"

using namespace std;

template <class T>
class CardStack{
private:
	vector<T> deck;
	vector<T> discard_pile;

public:
	void Reset(int num_cards);
	T Draw();
	void Discard(T card);
	void ShuffleDiscardIntoDeck();
}

template <class T>
void CardStack::Reset(int num_cards){
	deck.resize(num_cards);
	for(int i = 0; i < num_cards; i++){
		deck[i] = (T)i;
	}
	ShuffleDiscardIntoDeck();
}

template <class T>
T CardStack::Draw(){
	if (deck.size() == 0){
		ShuffleDiscardIntoDeck();
	}

	T card = deck.back();
	deck.pop_back();

	return card;
}

template <class T>
void CardStack::Discard(T card){
	discard_pile.push_back(card);
}

template <class T>
void CardStack::ShuffleDiscardIntoDeck(){
	deck.resize(discard_pile.size());
	for(unsigned int i = 0; i < deck.size(); i++){
		deck[i] = discard_pile[i];
	}
	discard_pile.clear();

	for(unsigned int i = 0; i < deck.size(); i++){
		deck[i] = deck[rng.IRandom(deck.size())];
	}
}

#endif