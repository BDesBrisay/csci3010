#include <iostream>
#include <math.h>
#include "Point.h"

Point::Point() {
  x_ = 0;
  y_ = 0;
}

double Point::distance(Point p) {
  int diffX = abs(p.x_ - x_);
  int diffY = abs(p.y_ - y_);

  double diff = sqrt(pow(diffX, 2) + pow(diffY, 2));

  return diff;
}