#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;

// contruct a point with default [0,0]
Point::Point() {
  x_ = 0;
  y_ = 0;
}

double Point::distance(Point p) {
  // get absolute diff between the two points
  int diffX = abs(p.x_ - x_);
  int diffY = abs(p.y_ - y_);

  // a^2 + b^2 = c^2
  return sqrt(pow(diffX, 2) + pow(diffY, 2));
}

void Point::translate(int inc) {
  // add increment to points
  x_ += inc;
  y_ += inc;

  // print out what happened
  cout << "Translated point by " << inc << endl;
}