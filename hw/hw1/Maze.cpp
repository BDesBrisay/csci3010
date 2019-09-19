#include <iostream>
#include <string>
#include "Maze.h"

using namespace std;


string SquareTypeStringify(SquareType t) {
  if (t == SquareType::Exit) return "\xF0\x9F\x8C\x80";
  if (t == SquareType::Wall) return "\xE2\xAC\x9C";
  if (t == SquareType::Human) return "\xF0\x9F\x90\x99";
  if (t == SquareType::Enemy) return "E";
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
  
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr_[i][j] = SquareType::Empty;
    }
  }

  srand(time(NULL));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // 20% chance to place a wall
      int wall = rand() % 100;
      int treasure = rand() % 100;

      if (wall < 20) {
        arr_[i][j] = SquareType::Wall;
      }
      else if (treasure < 10) {
        arr_[i][j] = SquareType::Treasure;
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

SquareType Board::GetExitOccupant() {
  int rows = get_rows();
  int cols = get_cols();
  return arr_[rows][cols];
}