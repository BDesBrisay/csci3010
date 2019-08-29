#include <iostream>
#include "Point.h"

using namespace std;

int main() {
  cout << "Hello World" << endl;

  Point p1;
  p1.setX(4);
  p1.setY(2);

  Point p2;
  p2.setX(3);

  p1.distance(p2);

  cout << p1.x_ << " - " << p1.y_ << endl;

  return 0;
}