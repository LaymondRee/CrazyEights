/**************************************************
 ** Program Filename: game.cpp
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Handles all moving cards
 ** Input: choose_card/choose_suit
 ** Output: crazy eights game
**************************************************/

#include <iostream>
#include "deck.h"
#include "player.h"
#include "game.h"

using namespace std;

/**************************************************
 ** Function: Game
 ** Description: Shuffles deck and deals cards
 ** Pre-Conditions: None
 ** Post-Conditions: Initialized game
**************************************************/
Game::Game(){
	cards.shuffle();

	//Deals 7 cards to each player
	for(int i = 0; i < 7; i++){
		players[0].draw_card(cards.draw_deck());
		players[1].draw_card(cards.draw_deck());
	}

	//Set the 15th card in the deck to the pile
	pile = cards.draw_deck();
}

Game::~Game(){


}

/**************************************************
 ** Function: p_turn
 ** Description: Handles the player's turn
 ** Pre-Conditions: None
 ** Post-Conditions: Player's turn
**************************************************/
void Game::p_turn(){
	bool can_play;

	do{
		cout << "-------Pile-------" << endl;
		pile.print_card();
		cout << "-------Pile-------" << endl << endl;
		cout << "-------Hand-------" << endl;
		players[0].hand.print_hand();
		cout << "-------Hand-------" << endl;
		cout << endl;

		can_play = players[0].draw_or_play(pile);

		if(can_play == true){
			p_turn_true();

			//Returns to main if end_game conditions met
			end_game = game_over();
			if(end_game == true){
				return;
		}

		}else if(can_play == false){
			p_turn_false();

			//Returns to main if deck is empty and no playable cards
			end_game = game_over();
			if(cards.get_n_cards() == 0){
				return;
			}
		}

	}while(can_play == false);
}

/**************************************************
 ** Function: p_turn_true
 ** Description: Handles the player playing a card
 ** Pre-Conditions: Player can play a card
 ** Post-Conditions: Player plays a card
**************************************************/
void Game::p_turn_true(){
	int choose_card;
	int choose_suit;

	cout << "Choose a card to play: ";
	cin >> choose_card;
	cout << endl;

	//Checks to see if player is selecting a playable card
	while((players[0].hand.get_cards(choose_card).get_value() != pile.get_value() && players[0].hand.get_cards(choose_card).get_suit() != pile.get_suit()) && players[0].hand.get_cards(choose_card).get_value() != 8){
		cout << "Input a valid card: ";
		cin >> choose_card;
	}

	//Lets player choose suit when 8 is played
	if(players[0].hand.get_cards(choose_card).get_value() == 8){
		cout << endl << "What would you like to change the suit to?" << endl;
		cout << "(1) - Spades" << endl;
		cout << "(2) - Hearts" << endl;
		cout << "(3) - Clubs" << endl;
		cout << "(4) - Diamonds" << endl;
		cin >> choose_suit;
		pile.set_card(8, choose_suit);

	}else{
		pile = players[0].hand.get_cards(choose_card);
	}
	players[0].play_card(choose_card);	
}

/**************************************************
 ** Function: p_turn_false
 ** Description: Handles the player drawing a card
 ** Pre-Conditions: Player can't play a card
 ** Post-Conditions: Player draws a card
**************************************************/
void Game::p_turn_false(){
	string buffer;

	cout << "No playable cards, press enter to draw a card..." << endl;
	cin.ignore();
	getline(cin, buffer);
	players[0].draw_card(cards.draw_deck());
}

/**************************************************
 ** Function: c_turn
 ** Description: Handles the computers's turn
 ** Pre-Conditions: None
 ** Post-Conditions: Computer's turn
**************************************************/
void Game::c_turn(){
	bool can_play;

	do{
		cout << "-------Pile-------" << endl;
		pile.print_card();
		cout << "-------Pile-------" << endl << endl;

		can_play = players[1].draw_or_play(pile);

		if(can_play == true){
			c_turn_true();

			//Returns to main if end_game conditions met
			end_game = game_over();
			if(end_game == true){
				return;
			}
		}else if(can_play == false){
			c_turn_false();

			//Returns to main if deck is empty and no playable cards
			end_game = game_over();
			if(cards.get_n_cards() == 0){
				return;
			}
		}

	}while(can_play == false);
}

/**************************************************
 ** Function: c_turn_true
 ** Description: Handles computer playing a card
 ** Pre-Conditions: Computer can play a card
 ** Post-Conditions: Computer plays card
**************************************************/
void Game::c_turn_true(){
	int choose_card;

	choose_card = players[1].draw_or_play2(pile);
	cout << "Computer is playing ";
	players[1].hand.get_cards(choose_card).print_card();
	cout << endl;
	pile = players[1].hand.get_cards(choose_card);
	players[1].play_card(choose_card);

}

/**************************************************
 ** Function: c_turn_false
 ** Description: Handles computer drawing a card
 ** Pre-Conditions: Computer can't play a card
 ** Post-Conditions: Computer draws card
**************************************************/
void Game::c_turn_false(){
	string buffer;

	cout << "Computer is drawing a card, press enter to continue..." << endl;
	cin.ignore();
	getline(cin, buffer);
	players[1].draw_card(cards.draw_deck());

}

/**************************************************
 ** Function: game_over
 ** Description: Checks if game is over
 ** Pre-Conditions: None
 ** Post-Conditions: True/False
**************************************************/
bool Game::game_over(){
	if(players[0].hand.get_n_cards() == 0){
		cout << "Player wins!" << endl;
		return true;
	}else if(players[1].hand.get_n_cards() == 0){
		cout << "Computer wins!" << endl;
		return true;
	}else if(cards.get_n_cards() == 0 && (players[0].hand.get_n_cards() <= players[1].hand.get_n_cards())){
		cout << "Player wins!" << endl;
		return true;
	}else if(cards.get_n_cards() == 0 && (players[1].hand.get_n_cards() < players[0].hand.get_n_cards())){
		cout << "Computer wins!" << endl;
		return true;
	}
	return false;
}

/**************************************************
 ** Function: get_end_game
 ** Description: gets value of end_game
 ** Pre-Conditions: None
 ** Post-Conditions: True/False
**************************************************/
bool Game::get_end_game(){
	return end_game;
}
