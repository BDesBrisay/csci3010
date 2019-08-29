#ifndef POINT
#define POINT
 
class Point {
  public:
    // contructor
    Point();

    // getters
    int getX() { return x_; }
    int getY() { return y_; }

    // setters
    void setX(int val) { x_ = val; }
    void setY(int val) { y_ = val; }

    // other methods
    double distance(Point p);
    void translate(int inc);

    // initialize point values
    int x_;
    int y_;
};
 
#endif