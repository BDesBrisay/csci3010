#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Maze.h"

using namespace std;

int main() {
  Player * p1 = new Player("Wanda", true);
  Maze * maze = new Maze();
  
  maze->NewGame(p1, 2);

  return 0;
}