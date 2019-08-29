#ifndef POINT
#define POINT
 
class Point {
  public:
    Point();

    int getX() { return x_; }
    int getY() { return y_; }

    void setX(int val) { x_ = val; }
    void setY(int val) { y_ = val; }

    double distance(Point p);

    int x_;
    int y_;
};
 
#endif