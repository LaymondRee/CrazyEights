/**************************************************
 ** Program Filename: game.h
 ** Author: Raymond Lee
 ** Date: 4-25-2021
 ** Description: Contains all members of Game class
**************************************************/

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game{
	private:
		Deck cards;
		Player players[2];
		int n_cards;
		Card pile;
		bool end_game;
	public:
		Game();
		~Game();
		void p_turn();
		void p_turn_true();
		void p_turn_false();
		void c_turn();
		void c_turn_true();
		void c_turn_false();
		bool game_over();
		bool get_end_game();
};

#endif
