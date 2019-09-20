#include <iostream>
#include <string>
#include "Maze.h"

using namespace std;

Maze::Maze() {
  cout << "New Maze!" << endl;
  turn_count_ = 0;
}

void Maze::NewGame(Player * human, const int enemies) {
  players_.push_back(human);
  
  Board * b = new Board(enemies);
  board_ = b;
  int cols = board_->get_cols() - 1;

  for (int i = 0; i < enemies; i++) {
    string name = "Enemy " + to_string(i + 1);
    Player * p = new Player(name, false);
    Position pos = { .row = 0, .col = cols - i };
    p->SetPosition(pos);

    players_.push_back(p);
  }

  Player * first = players_.front();

  TakeTurn(first);
}

void Maze::TakeTurn(Player * p) {
  cout << *board_ << endl;

  if (IsGameOver()) {
    cout << GenerateReport() << endl;
    cout << "GAME OVER" << endl;
  }
  else {
    cout << GenerateReport() << endl;
    vector<Position> moves = board_->GetMoves(p);

    cout << p->get_name() << " can go: ";
    for (Position pos : moves) {
      cout << p->ToRelativePosition(pos) << " ";
    }
    cout << endl;

    Position theMove;
    bool validInput = false;
    while (!validInput) {
      string input;
      cout << "Enter your choice: ";
      cin >> input;

      for (Position pos : moves) {
        string move = p->ToRelativePosition(pos);
        if (StringEquals(input, move)) {
          theMove = pos;
          validInput = true;
        }
      }
    }

    board_->MovePlayer(p, theMove);

    // next turn
    turn_count_++;
    Player * next = GetNextPlayer();
    TakeTurn(next);
  }
}

Player * Maze::GetNextPlayer() {
  int index = turn_count_ % players_.size();
  return players_.at(index);
}

bool Maze::IsGameOver() {
  SquareType end = board_->GetExitOccupant();
  bool has_human = board_->HasHuman();

  if (end == SquareType::Human) return true;
  if (!has_human) return true;

  cout << (end == SquareType::Human) << endl;
  cout << !has_human << endl;
  
  return false;
}

string Maze::GenerateReport() {
  string report = "";
  
  for (Player * p : players_) {
    report += p->Stringify() + " ";
  }

  return report;
}

bool Maze::StringEquals(string & s1, string & s2) {
	return (
    (s1.size() == s2.size()) && 
    equal(s1.begin(), s1.end(), s2.begin(), [](char & c1, char & c2) {
      return (c1 == c2 || toupper(c1) == toupper(c2));
    })
  );
}