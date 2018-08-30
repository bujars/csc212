#include "Sefa_B_HW1.h"
#include <iostream>
using namespace std;

int main(){
	Point pt1;
	Point pt2(2, 3, 4);
	cout << pt1.getX() << "\n"; 
	cout << pt2.getX() << "\n";
	pt1.setXYZ(1, 4, 2);
	double dist = pt1.distance();
	
	/*Point pt1 = new Point();*/
	cout << pt1.getX() << "\n";
	pt1.print();
	return 0;
}
