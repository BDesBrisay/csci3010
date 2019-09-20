#include <iostream>
#include <string>
#include "Board.h"

using namespace std;


string SquareTypeStringify(SquareType t) {
  if (t == SquareType::Exit) return "\xF0\x9F\x8C\x80";
  if (t == SquareType::Wall) return "\xE2\xAC\x9C";
  if (t == SquareType::Human) return "\xF0\x9F\x90\x99";
  if (t == SquareType::Enemy) return "\xF0\x9F\x91\xB9";
  if (t == SquareType::Treasure) return "\xF0\x9F\x8E\x81";
  else return "\xE2\xAC\x9B";
}

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

Board::Board() {
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

  // regardless of what was there before, set start and end points to Human and Exit
  arr_[0][0] = SquareType::Human;
  arr_[rows - 1][cols - 1] = SquareType::Exit;
}

SquareType Board::get_square_value(Position pos) const {
  return arr_[pos.row][pos.col];
}; 

void Board::SetSquareValue(Position pos, SquareType value) {
  arr_[pos.row][pos.col] = value;
}

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

bool Board::MovePlayer(Player * p, Position pos) {
  Position old = p->get_position();
  arr_[old.row][old.col] = SquareType::Empty;

  SquareType newSquare = arr_[pos.row][pos.col];
  if (newSquare == SquareType::Treasure) {
    p->ChangePoints(100);
  }

  if (p->is_human()) {
    arr_[pos.row][pos.col] = SquareType::Human;
  }
  else {
    arr_[pos.row][pos.col] = SquareType::Enemy;
  }

  p->SetPosition(pos);
  
  if (p->get_position() == pos) return 1;
  return 0;
}

SquareType Board::GetExitOccupant() {
  int rows = get_rows();
  int cols = get_cols();
  return arr_[rows][cols];
}