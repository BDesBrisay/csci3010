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
  // create 3 multidimensional points
  Point p1;
  p1.setCoord(1);
  p1.setCoord(1);
  p1.setCoord(1);

  Point p2;
  p2.setCoord(2);
  p2.setCoord(2);
  p2.setCoord(2);

  Point p3;

  // distance between 1 and 2
  cout << p1.distance(p1, p2) << endl;

  // testing distance function error handling
  cout << p1.distance(p1, p3) << endl;


  // Translate +1
  p2.translate(1);

  // new distance between 1 and 2
  cout << p1.distance(p1, p2) << endl;


  // Translate -1
  p1.translate(-1);

  // new distance between 1 and 2
  cout << p1.distance(p1, p2) << endl;

  
  // try and translate a point with no values
  p3.translate(5);

  return 0;
}