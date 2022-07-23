/**************************************************
 ** Program Filename: deck.cpp
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Handles 52 cards
 ** Input: None
 ** Output: Initialized deck/Shuffled deck
**************************************************/

#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;


/**************************************************
 ** Function: Deck
 ** Description: Initializes deck
 ** Pre-Conditions: Card array exists
 ** Post-Conditions: Initialized deck
**************************************************/
Deck::Deck(){
	int i;
	int j;
	int index = 0;

	n_cards = 52;

	for(i = 1; i <= 13; i++){
		for(j = 1; j <= 4; j++){
			cards[index].set_card(i, j);
			index++;
		}
		if(index == 51)
			break;
	}	
}

Deck::~Deck(){

}

/**************************************************
 ** Function: print_deck
 ** Description: Prints all cards in deck
 ** Pre-Conditions: Card array exists
 ** Post-Conditions: Prints all cards
**************************************************/
void Deck::print_deck(){
	for(int i = 0; i < 52; i++){
		cards[i].print_card();
	}
}

/**************************************************
 ** Function: shuffle
 ** Description: Randomizes card order in deck
 ** Pre-Conditions: Deck exists
 ** Post-Conditions: returns randomized card array
**************************************************/
void Deck::shuffle(){
	srand(time(NULL));
	Card tempcard[52] = cards;
	int cards_left = 52;
	int rand_num;

	//Sets random card at index starting at index 1
	//Shifts all indexes over starting from ran_num
	for(int i = 0; i < 52; i++){
		int count = 1;
		rand_num = rand() % cards_left;
		cards[i] = tempcard[rand_num];
	
		for(int j = rand_num; j < cards_left - 1; j++){
			tempcard[rand_num + count - 1] = tempcard[rand_num + count];
			count ++;
		}
		cards_left --;
	}
}

/**************************************************
 ** Function: draw_deck
 ** Description: Removes card from deck
 ** Pre-Conditions: Player draws a card
 ** Post-Conditions: Deck with card removed
**************************************************/
Card Deck::draw_deck(){
	n_cards -= 1;

	return cards[n_cards];
}

/**************************************************
 ** Function: get_n_cards
 ** Description: Gets value of n_cards
 ** Pre-Conditions: Deck exists
 ** Post-Conditions: returns n_cards
**************************************************/
int Deck::get_n_cards(){
	return n_cards;
}
