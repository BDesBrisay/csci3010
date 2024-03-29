#ifndef _MAZE_H_
#define _MAZE_H_

#include <vector>
#include "Board.h"

using namespace std;

class Maze {
public:
//	// TODO: implement these functions
	Maze(); // constructor
//
//	// initialize a new game, given one human player and 
//	// a number of enemies to generate
	void NewGame(Player *human, const int enemies, const int max_turn_count);
//
//	// have the given Player take their turn
	void TakeTurn(Player *p);
//
//	// Get the next player in turn order
	Player * GetNextPlayer();
//
//	// return true iff the human made it to the exit 
//	// or the enemies ate all the humans
	bool IsGameOver();
//
//	// You probably want to implement these functions as well
//	// string info about the game's conditions after it is over
	string GenerateReport();
//	friend std::ostream& operator<<(std::ostream& os, const Maze &m);

	bool StringEquals(string & s1, string & s2);	

private:
	Board *board_; 
	vector<Player *> players_;
	int turn_count_;
	// ADDED TO LIMIT NUMBER OF TURNS TAKEN
	int max_turn_count_;
//
//	// you may add more fields, as needed
//
};  // class Maze

#endif  // _MAZE_H_
