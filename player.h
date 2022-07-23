/**************************************************
 ** Program Filename: player.h
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Contains all members of Player class
**************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class Player{
	public:
		Hand hand;
		string name;
	public:
		Player();
		~Player();
		void draw_card(Card);
		void play_card(int);
		bool draw_or_play(Card);
		int draw_or_play2(Card);
		Hand get_hand();
};

#endif
