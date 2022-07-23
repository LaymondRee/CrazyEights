/**************************************************
 ** Program Filename: card.cpp
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Handles individual cards
 ** Input: Value/Suit
 ** Output: Card
**************************************************/

#include <iostream>
#include "card.h"

using namespace std;

Card::Card(){

}

Card::~Card(){

}

/**************************************************
 ** Function: set_card
 ** Description: Sets value and suit of card
 ** Parameters: i, j
 ** Pre-Conditions: All parameters exist
 ** Post-Conditions: Card initialized
**************************************************/
void Card::set_card(int i, int j){
	value = i;
	suit = j;
}

/**************************************************
 ** Function: print_card
 ** Description: Prints the value and suit of card
 ** Pre-Conditions: Card exists
 ** Post-Conditions: Print value and suit of card
**************************************************/
void Card::print_card(){
	if(value == 1)
		cout << "Ace of ";
	else if(value == 11)
		cout << "Jack of ";
	else if(value == 12)
		cout << "Queen of ";
	else if(value == 13)
		cout << "King of ";
	else
		cout << value << " of ";

	if(suit == 1)
		cout << "Spades" << endl;
	else if(suit == 2)
		cout << "Hearts" << endl;
	else if(suit == 3)
		cout << "Clubs" << endl;
	else if (suit == 4)
		cout << "Diamonds" << endl;
}

/**************************************************
 ** Function: get_value
 ** Description: Gets value of card
 ** Pre-Conditions: Card exists
 ** Post-Conditions: returns value
**************************************************/
int Card::get_value(){
	return value;
}

/**************************************************
 ** Function: get_suit
 ** Description: Gets suit of card
 ** Pre-Conditions: Card exists
 ** Post-Conditions: returns suit
**************************************************/
int Card::get_suit(){
	return suit;
}
