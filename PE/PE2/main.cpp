#include <iostream>
#include "Point.h"

using namespace std;

/*
void printCoord(int i, Point p) {
  cout << "Point " << i << ": (" << p.x_ << "," << p.y_ << ")" << endl;
}

void printDistances(Point p1, Point p2, Point p3) {
  cout << endl;
  cout << "p1 to p2: " << p1.distance(p2) << endl;
  cout << "p2 to p3: " << p2.distance(p3) << endl;
  cout << "p3 to p1: " << p3.distance(p1) << endl;
  cout << endl;
}
*/
int main() {
  // hell o world test
  // cout << "Hello World" << endl;

  // create 3 points
  Point p1;
  p1.setCoord(3);
  p1.setCoord(2);
  p1.setCoord(1);

  Point p2;
  p2.setCoord(2);
  p2.setCoord(4);
  p2.setCoord(2);

  p1.distance(p1, p2);

  // print initial coords
  // printCoord(1, p1);
  // printCoord(2, p2);
  // printCoord(3, p3);

  // print initial distances
  // printDistances(p1, p2, p3);

  return 0;
}