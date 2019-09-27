/*
Authors:
David Skrenta
Bryce DesBrisay

Original bugs: Shrink rectangle does not properly modify point1 coordinates
*/
#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(Point p1, Point p2) {
  // check if valid rectangle
  if (p1.x >= p2.x || p1.y >= p2.y) {
    std::cout << "Point's are invalid, unable to make rectangle." << std::endl;
    Point e1 = { x: 0, y: 0 };
    Point e2 = { x: 1, y: 1 };
    
    p1_ = e1;
    p2_ = e2;
  }
  else {
    p1_ = p1;
    p2_ = p2;
  }
}

int Rectangle::GetWidth() {
  return p2_.x - p1_.x;
}

int Rectangle::GetHeight() {
  return p2_.y - p1_.y;
} 

bool Rectangle::Overlaps(Rectangle& other) {
  Point o1 = other.get_p1();
  Point o2 = other.get_p2();

  // rectangle to the side of the other
  if (p1_.x > o2.x || p2_.x < o1.x) return false;
  // rectangle above/below the other
  if (p1_.y > o2.y || p2_.y < o2.y) return false;

  return true;
}

int Rectangle::CalculateArea() {
  return Rectangle::GetWidth() * Rectangle::GetHeight();
}

void Rectangle::Expand() {
  p1_ = { x: p1_.x - 1, y: p1_.y - 1 };
  p2_ = { x: p2_.x + 1, y: p2_.y + 1 };
}

void Rectangle::Shrink() {
  p1_ = { x: p1_.x + 1, y: p1_.y + 1 };
  p2_ = { x: p2_.x - 1, y: p2_.y - 1 };
}