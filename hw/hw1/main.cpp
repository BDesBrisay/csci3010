#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Maze.h"

using namespace std;

/**
 * main function creates a human player, maze
 * then starts a new maze game
 * 
 * COMMANDS TO START MAZE:
 * make
 * ./maze
 */
int main() {
  Player * p1 = new Player("Wanda", true);
  Maze * maze = new Maze();

  // @params - human player, number of enemies, max # of turns
  maze->NewGame(p1, 2, 8);

  return 0;
}