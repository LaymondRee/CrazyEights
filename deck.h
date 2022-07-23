/**************************************************
 ** Program Filename: deck.h
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Contains all members of Deck class
**************************************************/

#ifndef DECK_H
#define DECK_H

using namespace std;

#include <ctime>
#include <cstdlib>
#include "card.h"
#include "deck.h"

class Deck{
	private:
		Card cards[52];
		int n_cards;
	public:
		Deck();
		~Deck();
		void print_deck();
		void shuffle();
		Card draw_deck();
		int get_n_cards();
};

#endif
