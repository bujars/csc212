#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
#include <cmath> //For math functions
#include <cassert> //For assert function
using namespace std;

class Point{
  private:
    double x;
    double y;
    double z;
  public:
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double inX);
    void setY(double inY);
    void setZ(double inZ);
    void setXY(double inX, double inY);
    void setXYZ(double inX, double inY, double inZ);
    Point();
    Point(double inX, double inY, double inZ);
    Point(double inX, double inY);
    void origin();
    Point(const Point& P); //Copy constructor
    Point& operator=(Point P); //assignment function
    void print();
    double distance();
};
#endif
