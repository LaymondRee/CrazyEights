/**************************************************
 ** Program Filename: card.h
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Contains all members of Card class
**************************************************/

#ifndef CARD_H
#define CARD_H

using namespace std;

#include <string>
#include <ctime>

class Card{
	private:
		int value;
		int suit;
	public:
		Card();
		~Card();
		void set_card(int, int);
		void print_card();
		int get_value();
		int get_suit();
};

#endif
