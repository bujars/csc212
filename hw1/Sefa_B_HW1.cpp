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
/*Worst Time Complexity: O(1)*/
void Point::origin(){
	setXYZ(0,0,0);
}
/*Worst Time Complexity: O(1)*/
Point& Point::operator=(Point P){ //assignment function -- copies values from one point into the other. 
	this->x= P.x;
	this->y = P.y;
	this->z = P.z;
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
	double innerRoot = (x*x)+(y*y)+(z*z);
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
//got rid of mainpoint parameter because a point calls this function as its a memeber function
bool Point::line(Point secondPoint){
 //We know the origin is 0, 0, 0. First check if mainPoint and origin are the same point. 
 //Becasue then no line exists (technically infinitely many lines)

	Point vectPoints(secondPoint.x-x,secondPoint.y-y, secondPoint.z-z);
	vectPoints.print();
	//tOfCoordinate is the variable used to compare each variable for collinearity. 
	double tOfX = 0;
	if(vectPoints.getX() !=0)
		tOfX = -x/vectPoints.getX();
	cout << tOfX << "p\n";
	double tOfY = 0;
	if(vectPoints.getY() !=0)
		tOfY -y/vectPoints.getY();
	cout << tOfY << "y\n";
	double tOfZ = 0; 
	if(vectPoints.getZ() != 0)
		tOfZ = -z/vectPoints.getZ();
	cout << tOfZ << "d\n";
	//NOTE this can all be placed in one line...but for simplicity of reading. 
	if(tOfX == 0 && tOfY == tOfZ){
		return true;
	}
	else if(tOfY == 0 && tOfX == tOfZ){
		return true;
	}
	else if(tOfZ == 0 && tOfX == tOfY){
		return true;
	}
	else if(tOfX == tOfY && tOfX == tOfZ){
		return true;
	}
  /*if(mainPoint.getX() == 0 && mainPoint.getY() == 0 && mainPoint.getZ() ==0){
 	return false; 
 }*/
 return false; 
}

/* This function calculates the cross product between two points.
 * This function works by using the x, y, and z coordinate of the two points 
 * and applying the cross product formula (sample <yz2-y2z,....>). 
 * It returns a new point containing the cross product(Technically a cross product is in the form of a vector). 
 * Pre-Condition:
 * Post-Condition: THe cross product of two points is returned. 
 * Worst Time Complexity: O(1) - constant
 * */
Point Point::cross(Point secondPoint){
	double xCross = (y*secondPoint.z) - (secondPoint.y*z);
	double yCross = (z*secondPoint.x) - (x*secondPoint.z);
	double zCross = (x*secondPoint.y) - (secondPoint.x*y);
	Point crossProduct(xCross, yCross, zCross);
	return crossProduct; 
}

/* This function determines if a point is on a plane formed by the other 3 points.
 * Thie function works by
 * Pre-Condition: An array of 3 points, its size, and an addition point must be passed.
 * Post-Condition Returns if the point not in the array is in the plane formed by the 3 points in the array.
 * Worst Time Complexity: O(1) -- constant because its just small function calls?*/
bool plane(Point* points, int size, Point otherPoint){
	if(size!=3){
		return false;
	}
	Point u(points[1].getX() - points[0].getX(),points[1].getY() - points[0].getY(),points[1].getZ() - points[0].getZ());
	Point v(points[2].getX() - points[0].getX(),points[2].getY() - points[0].getY(),points[2].getZ() - points[0].getZ());
	Point normalVect = u.cross(v);
	double onPlane = (normalVect.getX()*(otherPoint.getX()-points[0].getX()))
		+ (normalVect.getY()*(otherPoint.getY()-points[0].getY()))
		+ (normalVect.getZ()*(otherPoint.getZ()-points[0].getZ()));
	return (onPlane == 0);
	
	
	
	return false;
}

/*Thought process: Find the centroid of the 4 points(kind of difficult here because our points are all unique and we dont know the size, so how should we check them is the tricky part). Once you have the centroid check the distance from it to each point. If its equal, then we have a square. 
 * Also, a square is 2d?????? Not 3d??
 * This funciton determines if any four points of all points given form a square. 
 * This function works by
 * Pre-Condition: Array of points must all be unique.
 * Post-Condition: Returns if any four points make a square or not.
 * Worst Time Complexity: O(n) -- As of now because of the for loop.
 * */
bool square(Point* points, int size){
	
	for(int i = 0; i < size; i++){
		for(int j = i+1; j < size-i; j++){
			for(int k = j+1; k<size-j; k++){
				for(int l = k+1; l < size-k; l++){
					
				}
			}
		}
		//if()
	}
	return false;
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
