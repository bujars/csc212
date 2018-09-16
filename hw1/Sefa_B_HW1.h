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
    void setX(double inX); /*NOTE set function paramters might be able to be constant...*/
    void setY(double inY);
    void setZ(double inZ);
    void setXY(double inX, double inY);
    void setXYZ(double inX, double inY, double inZ);
    Point(); //Default constructor
    Point(double inX, double inY, double inZ);
    Point(double inX, double inY);
    void origin();
    Point(const Point& P); //Copy constructor
    Point& operator=(Point P); //assignment function
    void print(); //Print function
    double distance(); //Distance function
	double distance(Point secondPoint); //Overwritten distance function /*NOTE this can generally be a const function, but to prevent errors from calling in a non-constant environement, ie loop it can lead to problems. --- well it did for me see pg.71 */
	bool line(Point secondPoint); //Functon that checks if points are collinear
	Point cross(Point secondPoint); //Function that gets cross product of points
	friend istream& operator >>(istream& ins, Point& p); //NOTE this is a friend function because when inputting we need to access x,y,z. 
};

Point operator +(const Point& pt1, const Point& pt2); //Overloading operator for addition.
Point operator -(const Point& pt1, const Point& pt2); //Overloading operator for subtraction.
ostream& operator <<(ostream& outs, const Point& p); //Overloading operator for output.
bool plane(Point* points, Point otherPoint); //Funciton that checks if a point is on a plane
bool square(Point* points, int size); //Function that checks if points make a square
Point centroid(Point* points, int size); //Function that gets the centroid of points.

#endif
