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
    // start diff at 0
    double diff = 0;

    for (int i = 0; i < p1.coords_.size(); i++) {
      // add the square of the difference between two points to the diff
      diff += pow(abs(p1.coords_[i] - p2.coords_[i]), 2);
    }

    // square root the overall diff to get the euclidean distance
    return sqrt(diff);
  }
  else {
    // error handling
    cout << "CANNOT CALCULATE DISTANCE - SIZES NOT EQUAL" << endl;
    // still need to return a double
    return 0.0;
  }
}

void Point::translate(int inc) {
  // check if there are any values to translate
  if (coords_.size() != 0) {
    // loop over all of the values of the point
    for (int i = 0; i < coords_.size(); i++) {
      // add increment to point
      coords_[i] += inc;
    }
    // print out what happened
    cout << "Translated point by " << inc << endl;
  }
  else {
    cout << "No values to translate" << endl;
  }
}