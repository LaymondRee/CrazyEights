/**************************************************
 ** Program Filename: player.cpp
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Holds the hand of each player
 ** Input: None
 ** Output: Player
**************************************************/

#include <iostream>
#include "hand.h"
#include "player.h"

using namespace std;

Player::Player(){


}

Player::~Player(){


}

/**************************************************
 ** Function: draw_card
 ** Description: Creates new card array and adds new card
 ** Parameters: new_card
 ** Pre-Conditions: Card array exists
 ** Post-Conditions: New card array
**************************************************/
void Player::draw_card(Card new_card){
	Hand hand_temp = hand;
	hand_temp.add_card(new_card);
	hand = hand_temp;
}

/**************************************************
 ** Function: play_card
 ** Description: Plays a card and remove it from hand
 ** Parameters: played_card
 ** Pre-Conditions: Card being played
 ** Post-Conditions: Card removed from hand
**************************************************/
void Player::play_card(int played_card){
	hand.subtract_card(played_card);
}

/**************************************************
 ** Function: play_or_draw
 ** Description: Decides if the player is playing or drawing a card
 ** Parameters: pile
 ** Pre-Conditions: Hand of player
 ** Post-Conditions: True/False
**************************************************/
bool Player::draw_or_play(Card pile){	
	bool can_play = hand.playable_card(pile);

	return can_play;
}

/**************************************************
 ** Function: draw_or_play2
 ** Description: Decides if computer is playing or drawing a card
 ** Parameters: pile
 ** Pre-Conditions: Hand of computer
 ** Post-Conditions: Value of card being played
**************************************************/
int Player::draw_or_play2(Card pile){
	int choose_card = hand.playable_card2(pile);

	return choose_card;
}

/**************************************************
 ** Function: get_hand
 ** Description: gets the hand of the player
 ** Pre-Conditions: hand exists
 ** Post-Conditions: returns hand
**************************************************/
Hand Player::get_hand(){
	return hand;
}
