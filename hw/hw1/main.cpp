#include <iostream>
#include "Player.h"

using namespace std;

int main() {
  Player * p1 = new Player("Wanda", true);

  cout << p1->get_position().col << endl;

  Position newPos;
  newPos = { .row = 0, .col = 1 };

  p1->SetPosition(newPos);

  cout << p1->get_position().col << endl;

  return 0;
}