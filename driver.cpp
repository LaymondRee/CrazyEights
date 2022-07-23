/**************************************************
 ** Program Filename: driver.cpp
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Playes the card game "Crazy Eights"
 ** Input: choose_card/choose_suit
 ** Output: Crazy Eights game
**************************************************/

#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

int main(){
	int again = 1;

	do{
		Game pgame;

		do{
			pgame.p_turn();
			if(pgame.get_end_game() == true){
				break;
			}
			pgame.c_turn();
		}while(pgame.get_end_game() == false);

		cout << "Would you like to play again? (1) - Yes, (0) - No" << endl;
		cin >> again;

	}while(again == 1);

	return 0;
}
