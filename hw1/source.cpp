#include "Sefa_B_HW1.h"
#include <iostream>
using namespace std;

int main(){

	/*Creating points for testing purposes -- testing constructors*/
	Point pt1(1,1,1);
	Point pt2(-1,-1,-1);
	Point pt3(2,4,6);
	Point origin; 

#if 0
	/*Testing getX functions*/
	cout << pt1.getX() << "\n"; 
	cout << pt2.getX() << "\n";
	cout << pt3.getX() << "\n";
#endif
#if 0
	/*Testing getY functions*/
	cout << pt1.getY() << "\n"; 
	cout << pt2.getY() << "\n";
	cout << pt3.getY() << "\n";
	/*Testing getZ functions*/
	cout << pt1.getZ() << "\n"; 
	cout << pt2.getZ() << "\n";
	cout << pt3.getZ() << "\n";
#endif
#if 0
	/*Testing set functions*/
	pt1.setX(2);
	pt1.setY(2);
	pt1.setZ(2);
	cout << pt1.getX() << "\n"; 
	cout << pt1.getY() << "\n";
	cout << pt1.getZ() << "\n";
#endif
#if 0
	pt2.setXY(1.3,1.3);
	cout << pt2.getX() << " " << pt2.getY() << "\n"; 
	pt2.setXYZ(-1,-1,-1);
	cout << pt2.getX()<< " "<<pt2.getY() << " "<< pt2.getZ() << "\n";
	pt1.setXYZ(1,1,1);
	cout << pt1.getX()<< " "<<pt1.getY() << " "<< pt1.getZ() << "\n";
#endif

#if 0 	
	/*Testing distance function*/
	double distPt1 = pt1.distance();
	cout << "Distance is " << distPt1 << "\n";
	double distPt2 = pt2.distance();
	cout << "Distance is " << distPt2 << "\n";
	double distPt3 = pt3.distance();
	cout << "Distance is " << distPt3 << "\n";
	double distOrg = origin.distance();
	cout << "Origin distance is " << distOrg << "\n";
#endif	
#if 0
	/*Testing print function*/
	pt1.print();
	pt2.print();
	pt3.print();
	origin.print();
	
#endif

#if 0
	/*Testing cross product function*/
	Point pt1To2 = pt1.cross(pt2);
	pt1To2.print();
	Point pt1To3 = pt1.cross(pt3);
	pt1To3.print();
	Point pt2To3 = pt2.cross(pt3);
	pt2To3.print();
	
#endif
#if 0
	/*Testing assingment operator*/
	pt1.print();
	pt1 = pt2;
	pt1.print();
	pt2.print();
	
#endif
#if 0
	/*Testing centroid function*/
	Point* points = new Point[4];
	points[0] = pt1;
	points[1] = pt2; 
	points[2] = pt3;
	points[3] = origin;
	Point cent = centroid(points, 4);
	cent.print();
#endif

//#if 0
	/*Testing line function*/
	bool isLinePt1Pt2 = pt1.line(pt2); //make line
	bool isLinePt1Pt3 = pt1.line(pt3); //dont make line
	cout << isLinePt1Pt2 << "\n";
	cout << isLinePt1Pt3 << "\n";
	
	Point pt4(1.5,1.5,1.5);
	Point pt5(2.5,2.5,2.5);
	bool isLinePt4Pt5 = pt4.line(pt5); //make line
	cout << isLinePt4Pt5 << "\n";

	Point pt6(1.25,1.25,1.25); //make line
	bool isLinePt6Pt5 = pt6.line(pt5);
	cout << isLinePt6Pt5 << "\n";

	bool isLinePtOriginOrigin = origin.line(origin);//does not make line
	cout << isLinePtOriginOrigin << "\n";

	Point p7(1,0,3);
	Point p8(2,0,6);
	bool isLinePt7Pt8 = p7.line(p8);//make line
	cout << isLinePt7Pt8 << "m\n";

	Point p9(1.2, 0, 3.2);
	bool isLinePt9Pt8 = p9.line(p8); //dont make line
	cout << isLinePt9Pt8 << "\n";


//#endif


	/*Testing overloading function*/
	Point p;
	/*Addition*/
	p = pt1+pt2;
	p.print();
	p = origin+pt1;
	p.print();
	p = pt2+pt3;
	p.print();
	p= pt4+pt5;
	p.print();
	/*Subtraction*/
	p = pt1-pt2;
	p.print();
	p = origin-pt1;
	p.print();
	p = pt2-pt3;
	p.print();
	p= pt4-pt5;
	p.print();

	p = origin;
	cout << p;
	cin >> p;
	cout << p;


	return 0;
}
