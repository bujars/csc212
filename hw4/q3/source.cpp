#include "Sefa_B_HW4_Q3.h"

int main(){
	priority_queue<int>a;
	a.push(1,1);
	a.push(2,1);
	a.push(3,2);
	a.push(4,2);
	a.push(5,5);
	a.push(6,0);
	a.push(100,100);	
	cout << "bugs everywhere " << endl<<endl;
	a.print();
	cout << endl << endl << "TOPPS " << a.top() << endl << endl;
	a.pop();
	cout << "first pop " << endl<<endl;
	a.print();
	cout << endl << endl << "TOPPS " << a.top() << endl << endl;
	a.push(200,200);
	cout << "first push " << endl<<endl;
	a.print();
	cout <<endl << endl << "TOPPS " << a.top() <<endl << endl;
//#if 0	
	a.pop();
	cout << "second pop " << endl<<endl;
	a.print();
	cout << endl << endl << "TOPPS " << a.top() << endl << endl;

	/*5, 3,4,1,2,6  this is what list should have. top = 5*/


//#if 0
	a.push(5,0);
	cout << "second push " << endl<<endl;
	a.print();
	cout << endl << endl << "TOPPS " << a.top() << endl << endl;
	/*list should be 5.5,3.2,4.2,1.1,6.0,5.0*/

//#if 0
	cout << "SIZE" <<a.size() << endl << endl;;
	a.push(6,6);
	cout << "third push " << endl<<endl;
	a.print();
	cout << endl << endl << "TOPPS " << a.top() << endl << endl;
	/*list should be 6.6, 5.5, 3.2, 4.2,1.1,6.0,5.0*/
//#if 0
	a.pop();
	a.push(7,0);//*/
	/*solutin should be 3 4 1 2 5*/
	cout <<endl << endl<< "top in source.cpp " << a.top() << endl;	
	a.print();
	cout << a.size() << endl;
//#endif
	return 0;
}
