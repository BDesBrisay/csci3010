#include <iostream>
#include "Player.h"
#include "Maze.h"

using namespace std;

int main() {
  Player * p1 = new Player("Wanda", true);

  cout << p1->get_position().col << endl;

  Position newPos = { .row = 0, .col = 1 };
  Position newPos1 = { .row = 0, .col = 2 };
  Position newPos2 = { .row = 1, .col = 1 };

  p1->SetPosition(newPos);

  cout << p1->get_position().col << endl;
  cout << p1->ToRelativePosition(newPos1) << endl;
  cout << p1->ToRelativePosition(newPos2) << endl;


  Board * b = new Board();

  cout << *b << endl;

  return 0;
}