#include <iostream>
#include <string>
#include "Maze.h"

using namespace std;

/**
 * Contructor that sets the turn count to 0
 */
Maze::Maze() {
  turn_count_ = 0;
}

/**
 * Creates a new game by making a board in the board_ field
 * Populates the players_ vector with a human and a given number of enemies with corresponding default positions
 * Then it starts the game by having the first player take their turn
 * 
 * @params Player * - human player to be played as, int - enemies count
 */
void Maze::NewGame(Player * human, const int enemies, const int max_turn_count) {
  // Normalizes the given max turn count to account for enemies' turns
  max_turn_count_ = max_turn_count * (enemies + 1);
  
  Board * b = new Board(enemies);
  board_ = b;
  int cols = board_->get_cols() - 1;

  players_.push_back(human);

  for (int i = 0; i < enemies; i++) {
    string name = "Enemy " + to_string(i + 1);
    Player * p = new Player(name, false);
    Position pos = { .row = 0, .col = cols - i };
    p->SetPosition(pos);

    players_.push_back(p);
  }

  Player * first = players_.front();

  TakeTurn(first);
}

/**
 * Take turn prints out the board
 * then checks if the game is over and generates a report if so
 * if game is not over yet, print out available moves and prompt for next move
 * evaluate prompt to see if it's a valid move
 * if it is, then move player to that new position
 * 
 * start the next turn by:
 * upping the turn count
 * get the next player
 * start their turn
 * 
 * @params Player * - player whos turn it is
 */
void Maze::TakeTurn(Player * p) {
  cout << *board_ << endl;

  if (IsGameOver()) {
    cout << GenerateReport() << endl;
  }
  else {
    vector<Position> moves = board_->GetMoves(p);

    cout << p->get_name() << " can go: ";
    for (Position pos : moves) {
      cout << p->ToRelativePosition(pos) << " ";
    }
    cout << endl;

    Position the_move;
    bool valid_input = false;
    while (!valid_input) {
      string input;
      cout << "Enter your choice: ";
      cin >> input;

      for (Position pos : moves) {
        string move = p->ToRelativePosition(pos);
        if (StringEquals(input, move)) {
          the_move = pos;
          valid_input = true;
        }
      }
    }

    board_->MovePlayer(p, the_move);

    // next turn
    turn_count_++;
    Player * next = GetNextPlayer();
    TakeTurn(next);
  }
}

/**
 * Gets the next player in from the players_ vector by using the turn count field
 * 
 * @return Player * - the next player up
 */
Player * Maze::GetNextPlayer() {
  int index = turn_count_ % players_.size();
  return players_.at(index);
}

/**
 * checks if human is at the exit square or if there is a human on the board
 * ADDITION: also checks if max_turn_count_ is exceeded
 * 
 * @return bool - is game over
 */
bool Maze::IsGameOver() {
  SquareType end = board_->GetExitOccupant();
  bool has_human = board_->HasHuman();

  if (end == SquareType::Human) return true;
  if (!has_human) return true;
  
  // Limit the number of turns allowed
  if (turn_count_ > max_turn_count_) {
    cout << "Max # of Turns Reached... GAME OVER" << endl;
    return true;
  }

  return false;
}

/**
 * prints out the name and points of all players
 * 
 * @return string - string of all players names and scores after another
 */
string Maze::GenerateReport() {
  string report = "";
  
  for (Player * p : players_) {
    report += p->Stringify() + " ";
  }

  return report;
}

/**
 * evaluates if two strings are equal in a case insensitive manner
 * 
 * @params strings - two strings to compare
 * @return bool - if the strings match
 */
bool Maze::StringEquals(string & s1, string & s2) {
	return (
    (s1.size() == s2.size()) && 
    equal(s1.begin(), s1.end(), s2.begin(), [](char & c1, char & c2) {
      return (c1 == c2 || toupper(c1) == toupper(c2));
    })
  );
}