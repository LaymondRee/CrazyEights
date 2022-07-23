/**************************************************
 ** Program Filename: hand.h
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Contains all members of Hand class
**************************************************/

#ifndef HAND_H
#define HAND_H

#include "card.h"

using namespace std;

class Hand{
	private:
		Card* cards;
		int n_cards;
	public:
		Hand();
		~Hand();
		Hand(const Hand&);
		Hand& operator=(const Hand&);
		void print_hand();
		void add_card(Card);
		void subtract_card(int);
		bool playable_card(Card);
		int playable_card2(Card);
		Card get_cards(int);
		int get_n_cards();
};

#endif
