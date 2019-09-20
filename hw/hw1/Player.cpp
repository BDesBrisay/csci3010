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
 * takes position and gives the relative direction from the player
 * 
 * @return string - direction of position from player
 */
string Player::ToRelativePosition(Position pos)  {
  if (pos.row == pos_.row) {
    // in the same row
    if (pos.col > pos_.col) return "RIGHT";
    else return "LEFT";
  }
  else {
    // in the same column
    if (pos.row > pos_.row) return "DOWN";
    else return "UP";
  }

  return "UNKNOWN DIRECTION";
}

/**
 * formats name and points of a player into a string
 * 
 * @return string - player's name and score in a sentence
 */
string Player::Stringify()  {
  string text = name_ + " has ";
  text += to_string(points_);
  text += " points.";

  return text;
}