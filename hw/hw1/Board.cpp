#include <iostream>
#include <string>
#include "Board.h"

using namespace std;


/**
 * given a SquareType, returns a matching emoji
 * 
 * @params SquareType - type of square we need a string for
 * @return string - emoji for squareType
 */
string SquareTypeStringify(SquareType t) {
  if (t == SquareType::Exit) return "\xF0\x9F\x8C\x80";
  if (t == SquareType::Wall) return "\xE2\xAC\x9C";
  if (t == SquareType::Human) return "\xF0\x9F\x90\x99";
  if (t == SquareType::Enemy) return "\xF0\x9F\x91\xB9";
  if (t == SquareType::Treasure) return "\xF0\x9F\x8E\x81";
  else return "\xE2\xAC\x9B";
}

/**
 * sets the << operator to handle printing out entire board at once
 * 
 * @params ostream - os to add to, Board - board to print
 * @return ostream - returns os with board printed out
 */
ostream& operator<<(ostream& os, const Board &b) {
  os << "\n";
  for (int i = 0; i < b.get_rows(); i++) {
    for (int j = 0; j < b.get_cols(); j++) {
      os << SquareTypeStringify(b.arr_[i][j]);
    }
    os << "\n";
  }
  return os;
}

/**
 * Constructor to setup board and populate it with SquareTypes
 * 
 * @params int - enemy count
 */
Board::Board(const int enemies) {
  int cols = get_cols();
  int rows = get_rows();

  srand(time(NULL));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int wall = rand() % 100;
      int treasure = rand() % 100;

      // 20% chance to place a wall
      if (wall < 20) {
        arr_[i][j] = SquareType::Wall;
      }
      // 10% chance to place treasure if not a wall
      else if (treasure < 10) {
        arr_[i][j] = SquareType::Treasure;
      }
      // everything else should be empty
      else {
        arr_[i][j] = SquareType::Empty;
      }
    }
  }

  // place enemies at the top right of the board
  for (int i = 0; i < enemies; i++) {
    arr_[0][cols - 1 - i] = SquareType::Enemy;
  }

  // regardless of what was there before, set start and end points to Human and Exit
  arr_[0][0] = SquareType::Human;
  arr_[rows - 1][cols - 1] = SquareType::Exit;
}

/**
 * gives the type of a square at a given position
 * 
 * @params Position - position to evaluate
 * @return SquareType - type of square at given position
 */
SquareType Board::get_square_value(Position pos) const {
  return arr_[pos.row][pos.col];
}; 

/**
 * sets the value of a square at a position
 * 
 * @params Position - position to change, SquareType - new type value to put at position
 */
void Board::SetSquareValue(Position pos, SquareType value) {
  arr_[pos.row][pos.col] = value;
}

/**
 * gets all available moves for a player (not a wall or off of board)
 * 
 * @params Player * - player to use as reference point
 * @return vector<Position> - vector of available moves' positions
 */
vector<Position> Board::GetMoves(Player * p) {
  vector<Position> res;

  Position pos = p->get_position();
  int col = pos.col;
  int row = pos.row;

  // Check if pos is not on outer edges of board for each direction
  if (col != 0) {
    Position newPos = { .row = row, .col = col - 1 };
    
    // Make sure newPos is not a wall
    if (get_square_value(newPos) != SquareType::Wall) {
      res.push_back(newPos);
    }
  }
  if (col != get_cols() - 1) {
    Position newPos = { .row = row, .col = col + 1 };
    
    if (get_square_value(newPos) != SquareType::Wall) {
      res.push_back(newPos);
    }
  }
  if (row != 0) {
    Position newPos = { .row = row - 1, .col = col };
    
    if (get_square_value(newPos) != SquareType::Wall) {
      res.push_back(newPos);
    }
  }
  if (row != get_rows() - 1) {
    Position newPos = { .row = row + 1, .col = col };
    
    if (get_square_value(newPos) != SquareType::Wall) {
      res.push_back(newPos);
    }
  }

  return res;
}

/**
 * actually moves a player on the board and changes the position of the player internally
 * if enemy moves onto another enemy, nothing happens
 * if player moves onto enemy player vanishes and is removed from the board (this is picked up by the IsGameOver function of Board)
 * 
 * @params Player * - player to move, Position - new position to move to
 * @return bool - if player was successfully moved
 */
bool Board::MovePlayer(Player * p, Position pos) {
  Position old = p->get_position();
  int rows = get_rows();
  int cols = get_cols();

  SquareType new_square = arr_[pos.row][pos.col];
  if (new_square == SquareType::Treasure) {
    p->ChangePoints(100);
  }

  if (p->is_human()) {
    // if new_square is enemy, enemy eats human
    if (new_square == SquareType::Enemy) {
      arr_[old.row][old.col] = SquareType::Empty;
      arr_[pos.row][pos.col] = SquareType::Enemy;
      p->SetPosition(pos);
    }
    // else move human
    else {
      arr_[old.row][old.col] = SquareType::Empty;
      arr_[pos.row][pos.col] = SquareType::Human;
      p->SetPosition(pos);
    }
  }
  // p is enemy and new_square is not, then move enemy
  else if (new_square != SquareType::Enemy) {
    if (old.row == rows - 1 && old.col == cols - 1) {
      // restore exit if enemy moves over it
      arr_[old.row][old.col] = SquareType::Exit;
    }
    else {
      arr_[old.row][old.col] = SquareType::Empty;
    }
    arr_[pos.row][pos.col] = SquareType::Enemy;
    p->SetPosition(pos);
    
  }
  
  if (p->get_position() == pos) return 1;
  return 0;
}

/**
 * gets SquareType of the exit square
 * 
 * @return SquareType - type of the last square on board
 */
SquareType Board::GetExitOccupant() {
  int rows = get_rows();
  int cols = get_cols();
  return arr_[rows - 1][cols - 1];
}

/**
 * helper function to check if a human is on the board
 * 
 * @return bool - if board has a human on it
 */
bool Board::HasHuman() {;
  int cols = get_cols();
  int rows = get_rows();
  
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (arr_[i][j] == SquareType::Human) {
        return true;
      }
    }
  }

  return false;
}