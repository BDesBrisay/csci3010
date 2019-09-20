#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Maze.h"

using namespace std;

int main() {
  Player * p1 = new Player("Wanda", true);

/*
  cout << p1->get_position().col << endl;

  Position newPos1 = { .row = 0, .col = 2 };
  Position newPos2 = { .row = 1, .col = 1 };

  p1->SetPosition(newPos);

  cout << p1->get_position().col << endl;
  cout << p1->ToRelativePosition(newPos1) << endl;
  cout << p1->ToRelativePosition(newPos2) << endl;
*/
  Position newPos = { .row = 0, .col = 1 };

  Board * b = new Board();

  cout << *b << endl;

  vector<Position> moves = b->GetMoves(p1);

  for (Position pos : moves) {
    cout << p1->ToRelativePosition(pos) << endl;
  }

  b->MovePlayer(p1, newPos);

  cout << *b << endl;

  vector<Position> moves2 = b->GetMoves(p1);

  for (Position pos : moves2) {
    cout << p1->ToRelativePosition(pos) << endl;
  }

  return 0;
}