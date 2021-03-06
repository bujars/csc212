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
/*   
 * This function prints out the x, y, and z coordinate of the Point that calls it. 
 * This function works by using the cout function to output the Point, in which the Point's x,y,z variables are accessed.
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
 * This function works by sqauring each x/y/z coordinate, adding them together, 
 * and taking the square root to provide a distance. 
 * (NOTE -- Mathematical forumla of distance)
 *
 * Pre-Condition: A point can only call this function (must have 3 double coordinates).
 * Post Condition: The distance of the point from the origin is provided in a decimal value. //The distance from the point to the origin is returned in a double value. 
 * Worst Time Complexity:O(1) */
double Point::distance(){
	double innerRoot = (x*x)+(y*y)+(z*z);
	double rad = sqrt(innerRoot);
	return rad;
}

double Point::distance(Point secondPoint){
	double innerRoot = ((secondPoint.x - x)*(secondPoint.x-x)) + ((secondPoint.y - y)*(secondPoint.y-y)) + ((secondPoint.z - z)*(secondPoint.z-z));
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
 * This function works by finding a scalar of the x,y,z component between the point that calls the function and secondPoint. The scalars of the x,y,z componenet are then checked to see if they are equal in value. If they are equal in value, true is returned, else false is returned. 
 * Pre-Condition: SecondPoint must be a Point with x,y, and z coord. (Double)/ Point must call the function and a Point must be inputed as a paramter. 
 * Post-Condition: Returns if whether or not the two points and the origin are collinear.
 * Worst Time Complexity: O(1);
 * */
//got rid of mainpoint parameter because a point calls this function as its a memeber function
bool Point::line(Point secondPoint){
 //We know the origin is 0, 0, 0. First check if mainPoint and origin are the same point. 
 //Becasue then no line exists (technically infinitely many lines)
	if((x==0 && y==0 && z==0)) // || (secondPoint.x==0 && secondPoint.y==0 && secondPoint.z==0)) /*NOTE not sure if point 2 can still be either of those points, i would assume it could because it would still be on the point of the line, ie if point 2 is just the origin again.*/
		return false;
#if 0
	/*NOTE its a member function so get rid of .getX() and use .x*/
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
#endif
	double tOfX = 0;
	double tOfY = 0;
	double tOfZ = 0;
	if(secondPoint.x != 0)
		tOfX = x/secondPoint.x;
	if(secondPoint.y !=0)
		tOfY = y/secondPoint.y;
	if(secondPoint.z != 0)
		tOfZ = z/secondPoint.z;
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
 * Pre-Condition: secondPoint must be a point.
 * Post-Condition: The cross product of two points is returned. (A point containing the values of their cross product)
 * Worst Time Complexity: O(1) - constant
 * */
Point Point::cross(Point secondPoint){
	double xCross = (y*secondPoint.z) - (secondPoint.y*z);
	double yCross = (z*secondPoint.x) - (x*secondPoint.z);
	double zCross = (x*secondPoint.y) - (secondPoint.x*y);
	Point crossProduct(xCross, yCross, zCross);
	return crossProduct; 
}

/* This function produces a new point that is the addition of the components of the two points(pt1 and pt2) being added.
 * This function works by taking the seperate componenets of each of the two points(pt1,pt2)...ie(pt1.x+pt2.x), 
 * adding them together, and storing them in a new point that is returned.
 * Pre-Condition: Two points(pt1 and pt2) must be passed to be added.
 * Post-Condiiton" A new point is retuned containing the indivually added componenets of the two points(pt1 and pt2). 
 * Worst Time Complexity: O(1);
 * */
Point operator +(const Point& pt1, const Point& pt2){
	Point added(pt1.getX()+pt2.getX(), pt1.getY()+pt2.getY(), pt1.getZ()+pt2.getZ());
	return added;
}

/* This function produces a new point that is the subtraction of the components of the two points(pt1 and pt2) being subtracted.
 * This function works by taking the seperate componenets of each of the two points(pt1,pt2)...ie(pt1.x-pt2.x), 
 * subtracting them each, and storing them in a new point that is returned.
 * Pre-Condition: Two points(pt1 and pt2) must be passed to be subtracted.
 * Post-Condiiton" A new point is retuned containing the indivually subtracted componenets of the two points(pt1 and pt2). 
 * Worst Time Complexity: O(1);
 * */
Point operator -(const Point& pt1, const Point& pt2){
	Point added(pt1.getX()-pt2.getX(), pt1.getY()-pt2.getY(), pt1.getZ()-pt2.getZ());
	return added;
}

/* This function takes in user input of a point(all three values -- doubles).
 * This function works by overloading the >> operand by letting users input points directing and storing the values into a point object (which values are then referenced to). \*NOTE this can use some clearning up*\
 * Pre-Condition: Operand (>>) must be used w/intput to point object. \*NOTE clean up -- follow textbook*\
 * Post-Condition: The x,y,z coordinates of point p have been read into ins. The return value is the istream of ins.
 * Worst Time Complexity: O(1);
 * */
istream& operator >>(istream& ins, Point& p){ //NOTE friend is only to be wrriten on the prototype not implementation.
	ins >> p.x >> p.y >> p.z; //is a friend function so can access memeber variables
	return ins;
}
/* This function outputs the point into the output steam. 
 * This function works by overloading the << operand by letting the point p be outputted onto the output stream outs. Individual components of point p are output one after the other. \*NOTE this can use some clearning up*\
 * Pre-Condition: Operand (<<) must be used w/output of point object. \*NOTE clean up -- follow textbook*\
 * Post-Condition: The x,y,z coordinates of point p have been written into outss. The return value is the ostream of outs.
 * Worst Time Complexity: O(1);
 * */
ostream& operator <<(ostream& outs, const Point& p){
	//outs << p.getX() << p.getY() << p.getZ();  //note not a member funciton so cant access variables
	outs << p.getX() << ", " << p.getY() << ", " << p.getZ() << "\n";
	return outs;
}



/* This function determines if a point is on a plane formed by the other 3 points.
 * Thie function works by
 * Pre-Condition: An array of 3 points, its size, and an addition point must be passed.
 * Post-Condition Returns if the point not in the array is in the plane formed by the 3 points in the array.
 * Worst Time Complexity: O(1) -- constant because its just small function calls?*/
bool plane(Point* points, Point otherPoint){ //Got rid of int size since we aren't given size - Timmy
	/*if(size!=3){
		return false;
	}*/
	Point u(points[1].getX() - points[0].getX(),points[1].getY() - points[0].getY(),points[1].getZ() - points[0].getZ());
	Point v(points[2].getX() - points[0].getX(),points[2].getY() - points[0].getY(),points[2].getZ() - points[0].getZ());
	Point normalVect = u.cross(v);
	double onPlane = (normalVect.getX()*(otherPoint.getX()-points[0].getX()))
		+ (normalVect.getY()*(otherPoint.getY()-points[0].getY()))
		+ (normalVect.getZ()*(otherPoint.getZ()-points[0].getZ()));
	return (onPlane == 0);
	
	

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
	
	if(size < 4){
		return false; 
	}
	for(int i = 0; i < size-3; i++){
		for(int j = i+1; j < size-2; j++){
			for(int k = j+1; k<size-1; k++){
				for(int l = k+1; l < size; l++){
					int threeOfFourPointsSize = 3;
					Point threeOfFourPoints[threeOfFourPointsSize];
					threeOfFourPoints[0] = points[j];
					threeOfFourPoints[1] = points[k];
					threeOfFourPoints[2] = points[l];
					if(plane(threeOfFourPoints, points[i])){
						double disIToJ = points[i].distance(points[j]);
						double disIToK = points[i].distance(points[k]);
						double disIToL = points[i].distance(points[l]);
						double disJToK = points[j].distance(points[k]);
						double disJToL = points[j].distance(points[l]);
						double disKToL = points[k].distance(points[l]);
						if((disIToJ == disJToK) && (disIToJ == disIToL)){
							if(disIToJ == disKToL){
								if(disIToK == disJToL){
									return true;
								}
							}
						}
						else if((disIToK == disJToK) && (disIToK == disIToL)){
							if(disIToK == disJToL){
								if(disIToJ == disKToL){
									return true;
								}
							}
						}
						else if((disIToJ == disIToK) && (disIToJ == disJToL)){
							if(disIToJ == disKToL){
								if(disIToL == disJToK){
									return true;
								}
							}
						}
					}
				}
			}
		}
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
	if(size<=0){
		Point p(0,0,0);
		return p;
	}
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
