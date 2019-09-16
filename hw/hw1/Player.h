#ifndef PLAYER
#define PLAYER
#include <string>

using namespace std;

class Player {
  public:
    Player();

    void move(int dir);
    void set_name(string name);

    /**
     * returns the name field of a player
     * 
     * @return Player's name
     */
    string get_name() { return name_; };

  private:
    string name_;
    int x_;
    int y_;
    int score_;
};

#endif