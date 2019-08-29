#ifndef POINT
#define POINT
#include <vector>

using namespace std;
 
class Point {
  public:
    // contructor
    Point();

    // getter
    int getCoord(int index) { return coords_[index]; }

    // setter
    void setCoord(int val) { coords_.push_back(val); }

    // other methods
    double distance(Point p1, Point p2);
    void translate(int inc);

    // initialize point values
    vector<int> coords_;
};
 
#endif