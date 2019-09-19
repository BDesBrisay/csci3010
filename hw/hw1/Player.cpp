#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

/**
 * Contructor assigns name and is_human
 */
Player::Player(const string name, const bool is_human) {
  name_ = name;
  is_human_ = is_human;
}

/**
 * Changes a players points
 * 
 * @params int - new point value to be added
 */
void Player::ChangePoints(const int x) {
  points_ += x;
}

/**
 * Sets a players position
 * 
 * @params Position - new position
 */
void Player::SetPosition(Position pos) {
  pos_ = pos;
}

/**
 * Prints out name and points of a player
 */
string Player::Stringify()  {
  string text = name_ + " has ";
  text += to_string(points_);
  text += " points.";

  return text;
}