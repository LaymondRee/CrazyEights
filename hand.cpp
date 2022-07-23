/**************************************************
 ** Program Filename: hand.cpp
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Handles array of cards
 ** Input: None
 ** Output: Array of cards
**************************************************/

#include <iostream>
#include "card.h"
#include "hand.h"

using namespace std;

/**************************************************
 ** Function: Hand
 ** Description: Initializes hand
 ** Pre-Conditions: None
 ** Post-Conditions: Creates new card array
**************************************************/
Hand::Hand(){
	n_cards = 0;
	cards = new Card[1];
}

/**************************************************
 ** Function: ~Hand
 ** Description: Deletes card array when out of scope
 ** Pre-Conditions: Card array exists
 ** Post-Conditions: Card array deleted
**************************************************/
Hand::~Hand(){
	delete[] cards;
}

/**************************************************
 ** Function: Hand
 ** Description: Copies hand during initialization
 ** Parameters: const Hand& old_hand
 ** Pre-Conditions: Another hand exists
 ** Post-Conditions: returns new card array
**************************************************/
Hand::Hand(const Hand& old_hand){
	n_cards = old_hand.n_cards + 1;
	cards = new Card[n_cards];
	for(int i = 0; i < n_cards - 1; i++){
		cards[i] = old_hand.cards[i];
	}
}

/**************************************************
 ** Function: operator=
 ** Description: Copies hand during redefinition
 ** Parameters: const Hand& old_hand
 ** Pre-Conditions: Another hand exists
 ** Post-Conditions: returns new card array
**************************************************/
Hand& Hand::operator=(const Hand& old_hand){
	n_cards = old_hand.n_cards;
	delete[] cards;
	cards = new Card[n_cards];
	for(int i = 0; i < n_cards; i++){
		cards[i] = old_hand.cards[i];
	}
	return *this;
}

/**************************************************
 ** Function: print_hand
 ** Description: Prints all cards in card array
 ** Pre-Conditions: Card array exists
 ** Post-Conditions: Printed cards
**************************************************/
void Hand::print_hand(){
	for(int i = 0; i < n_cards; i++){
		cout << "(" << i << ") ";
		cards[i].print_card();
	}
}

/**************************************************
 ** Function: add_card
 ** Description: Adds card to end of card array
 ** Parameters: new_card
 ** Pre-Conditions: Top card of deck
 ** Post-Conditions: Card array with new card
**************************************************/
void Hand::add_card(Card new_card){
	cards[n_cards - 1] = new_card;
}

/**************************************************
 ** Function: subtract_card
 ** Description: Removes card from hand array
 ** Parameters: played_card
 ** Pre-Conditions: Card being removed
 ** Post-Conditions: returns new array with card removed
**************************************************/
void Hand::subtract_card(int played_card){
	for(int i = played_card; i < n_cards - 1; i++){
		cards[i] = cards[i + 1];
	}
	n_cards -= 1;
}

/**************************************************
 ** Function: playable_card
 ** Description: Checks if card array has playable card
 ** Parameters: pile
 ** Pre-Conditions: Card on pile
 ** Post-Conditions: True/False
**************************************************/
bool Hand::playable_card(Card pile){
	//Checks if card being players is the same value or suit as pile
	//Also checks to see if it is an 8
	for(int i = 0; i < n_cards; i++){
		if(cards[i].get_value() == pile.get_value() || cards[i].get_suit() == pile.get_suit() || cards[i].get_value() == 8){
			return true;
		}
	}
	return false;
}

/**************************************************
 ** Function: playable_card2
 ** Description: Get the index to the playable card
 ** Parameters: pile
 ** Pre-Conditions: Card on pile
 ** Post-Conditions: index of playable of card
**************************************************/
int Hand::playable_card2(Card pile){
	for(int i = 0; i < n_cards; i++){
		if(cards[i].get_value() == pile.get_value() || cards[i].get_suit() == pile.get_suit() || cards[i].get_value() == 8){
			return i;
		}
	}
	return 0;
}

/**************************************************
 ** Function: get_cards
 ** Description: Gets a card from card array
 ** Parameters: choose_card
 ** Pre-Conditions: Card array exists
 ** Post-Conditions: returns card from card array
**************************************************/
Card Hand::get_cards(int choose_card){
	return cards[choose_card];
}

/**************************************************
 ** Function: get_n_cards
 ** Description: gets value for n_cards
 ** Pre-Conditions: None
 ** Post-Conditions: returns value of n_cards
**************************************************/
int Hand::get_n_cards(){
	return n_cards;
}
