#include <iostream>
#include <math.h>
#include <vector>
#include "Point.h"

using namespace std;

// contruct a point with default [0,0]
Point::Point() {
  // coords_ = vector<int>;
}

double Point::distance(Point p1, Point p2) {
  if (p1.coords_.size() == p2.coords_.size()) {
    cout << "EQUAL" << endl;
    double diff = 0;
    for (int i = 0; i < p1.coords_.size(); i++) {
      diff += pow(abs(p1.coords_[i] - p2.coords_[i]), 2);

      cout << diff << endl; 
    }

    cout << sqrt(diff) << endl;
    return sqrt(diff);
  }
  else {
    // error handling
    cout << "CANNOT CALCULATE DISTANCE - SIZES NOT EQUAL" << endl;
  }
  // get absolute diff between the two points
  // int diffX = abs(p.x_ - x_);
  // int diffY = abs(p.y_ - y_);

  // a^2 + b^2 = c^2
  // return sqrt(pow(diffX, 2) + pow(diffY, 2));

  return 0.0;
}

void Point::translate(int inc) {
  // add increment to points
  // x_ += inc;
  // y_ += inc;

  // print out what happened
  cout << "Translated point by " << inc << endl;
}