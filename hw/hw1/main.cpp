#include <iostream>
#include "Player.h"

using namespace std;

int main() {
  Player p1;
  p1.set_name("Wanda");

  cout << p1.get_name() << endl;

  return 0;
}