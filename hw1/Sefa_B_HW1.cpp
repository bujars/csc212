#include "Sefa_B_HW1.h"
#ifndef __POINT_CPP__
#define __POINT_CPP__

#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

Point::Point(){
	x = 0;
	y = 0;
	z = 0;
}
Point::Point(double inX, double inY, double inZ){
	x = inX;
	y = inY;
	z = inZ;
}
Point::Point(double inX, double inY){
	x = inX;
	y = inY;
	z = 0;
	}
Point::Point(const Point& P){
		x = P.getX();
		y = P.getY();
		z = P.getZ();
}
double Point::getX() const{
    return x;
}
double Point::getY() const{
	return y;
}
double Point::getZ() const{
    return z;
}
void Point::setX(double inX){
 	x = inX;
}
void Point::setY(double inY){
    y = inY;
}
void Point::setZ(double inZ){
    z = inZ;
}
void Point::setXY(double inX, double inY){
		x = inX;
		y = inY;
}
void Point::setXYZ(double inX, double inY, double inZ){
	x = inX;
	y = inY;
	z = inZ;
}
/*Time Complexity: O(1)*/
void Point::origin(){
	setXYZ(0,0,0);
}
/*Time Complexity: 4? One for calling function set and then 3 for get. So O(1)*/
Point& Point::operator=(Point P){ //assignment function
	setXYZ(P.getX(), P.getY(), P.getZ());
	return (*this); //We want to return the current Point object
	//which now has the assigned values of the other.
}
/* Time Complexitiy: 7. One for each <<.  
 * This function prints out the x, y, and z coordinate of the Point that calls it. 
 * This function  works by using the cout function to print message, and accesses the Point's x,y,z variables.
 * Pre-Condition: Object calling the function must be a Point.
 * Post:Condition: The coordinates of the Point are printed. 
 * Worst case complexity, O(1).*/
void Point::print(){
		cout << "Xcoord: " << x << " YCoord: " << y
			<< " Zcoord: " << z << endl;
		//NOTE not sure if it wants us to: cout << "(" << x << ", "<< y << ", " << z << ")\n";
	}
/*Time Complexity: I believe that for sqrt it is 1 
 * because we calculate the value of a singular value, not many.
 * (Size is independant here) 1 for x*x, 1 for y*y, x+y, y+z, z*z...etc. 
 * Eitherway, complexity is mesasured as whole, not individual. So O(n).  */

/* This function calculates the distance of a point from the origin. 
 * This function works by sqaureing each x/y/z coordinate, adding them together, 
 * and taking the square root to provide a distance. 
 * (NOTE -- Mathematical forumla of distance)
 *
 * Pre-Condition: A point can only call this function (must have 3 double coordinates).
 * Post Condition: The distance of the point from the origin is provided in a decimal value
 * Worst Time Complexity:O(1) */
double Point::distance(){
	double innerRoot = pow(x,2) + pow(y,2)+pow(z,2); /*Or switch to (x*x)+(y*y)+(z*z)*/
	double rad = sqrt(innerRoot);
	return rad;
}
/*double Point::distance(Point secondPoint){
	double dis = pow((secondPoint.getX()-x), 2) + pow((secondPoint.getY()-y),2) + pow((secondPoint.getZ()-z), 2);
	double root = sqrt(dis);
	return root;
}*/


//To determine if three points are on the same line, find the line of the origin and the first point. 
//Find y = mx+b. DO point slope formula. Then use third point and if statemenst to chack if they equal.
/* This function determins if three points, one being the orgin, are all collinear.
 * This function works by
 * Pre-Condition: 
 * Post-Condition: Returns whether or not the two points and the origin are collinear.
 * Worst Time Complexity: 
 * */
#if 0
bool Point::line(Point mainPoint, Point secondPoint){
 //We know the origin is 0, 0, 0. First check if mainPoint and origin are the same point. 
 //Becasue then no line exists (technically infinitely many lines)
 if(mainPoint.getX() == 0 && mainPoint.getY() == 0 && mainPoint.getZ() ==0){
 	return false; 
 }
 //double disMainToOrigin

}
#endif

/* This function calculates the cross product between two points.
 * This function works by using the x, y, and z coordinate of the two points 
 * and applying the cross product formula (sample <yz2-y2z,....>). 
 * It returns a new point containing the cross product(Technically a cross product is in the form of a vector). 
 * Pre-Condition:
 * Post-Condition: THe cross product of two points is returned. 
 * Worst Time Complexity: O(1) - constant
 * */
Point Point::cross(Point secondPoint){
	double xCross = (y*secondPoint.getZ()) - (secondPoint.getY()*z);
	double yCross = (z*secondPoint.getX()) - (x*secondPoint.getZ());
	double zCross = (x*secondPoint.getY()) - (secondPoint.getX()*y);
	Point crossProduct(xCross, yCross, zCross);
	return crossProduct; 
}

/* This function calculates the cetroid of an array of points.
 * This function works by going through each point, 
 * summing up their coordinates and getting the average of each corrdinate. 
 * Then it places each coordinate into a point to return.
 * Pre-Condition: Array must be of points.
 * Post-Condition: The centroid point of the points is returned.
 * Worst Time Complexity: O(n)
 * */
Point centroid(Point* points, int size){
	double xSum = 0;
	double ySum = 0;
	double zSum = 0;
	for(int i = 0; i < size; i++){
		xSum+= points[i].getX();
		ySum+= points[i].getY();
		zSum+= points[i].getZ();
	}
	double avgX = xSum/size;
	double avgY = ySum/size;
	double avgZ = zSum/size;
	Point cent(avgX, avgY, avgZ);
	return cent;
}

#endif
