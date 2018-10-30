#include "Sefa_B_HW4_Q4.h"

int main(){

	queue<int> a;
//#if 0
	a.push(1);
	cout << a.front() << endl;
	a.push(2);
	cout << a.front() << endl;
	a.push(3);
	cout << a.front() <<endl;
	a.push(4);
	a.push(5);
	a.push(6);
	a.pop();
	a.push(7);
	a.pop();
	a.push(8);
	a.pop();
	cout << a.front() << endl << endl;
	a.print();	
	cout << endl<< a.size() << endl;
	
	queue<int>b;
	b.push(11);
	b.push(12);
	b.push(13);
	b.push(14);
	b.push(15);
	b.print();
	queue<int>d;
	d=a;
	//#endif
//#if 0
	a = b;
	b=b;
	
	cout << "should be 11 12 13 14 15   "<<endl << endl;
	a.print();
	cout << "should be 11 12 13 14 15    "<<endl << endl;
	b.print();
	cout << "should be 4 5 6 7 8    "<<endl << endl;
	d.print();
	cout << endl << endl;
//#if 0
	queue<int>c(d);
	cout << endl << endl;
	c.print();
	cout << endl;
//#endif

	return 0;
}
