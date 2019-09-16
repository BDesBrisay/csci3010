#include <iostream>
#include "Player.h"

using namespace std;
/**
 * Contructor assigns default values to fields
 */
Player::Player() {
  name_ = "";
  x_ = 0;
  y_ = 4;
  score_ = 0;
}

/**
 * sets the name field of a player
 * 
 * @params name - New Name
 */
void Player::set_name(string name) {
  name_ = name;
}