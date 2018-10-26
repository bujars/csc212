#include "Sefa_B_HW4_Q2.h"

int main(){

	queue<int>a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	a.print();
	cout << endl<< a.size() << endl << endl;

	cout << a.front() << endl;
#if 0	
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.push(2);
	a.push(10);
	a.pop();
	cout << "NEW FRONT " <<a.front() << endl;;
	a.print();
#endif
	
	
	queue<int>b(a);
	cout << endl;
	//b.print();
	//b = a;
	b.print();
	

	cout << endl << endl;
	queue<int> d;
	d.push(7);
	d.push(8);
	d.push(9);
	d.push(10);
	d.push(11);
	d.push(12);
	d.print();
	/*cout << endl << endl << "what's this?" << endl;*/
	//	b = d;
	//d = b;
	//b.print();

	//cout << endl;
	
	cout << "Testing swap " << endl << endl;;
	b.swapQueues(d);
	d.swapQueues(b);
	b.print();
	cout << endl << endl;
	d.print();
	cout << endl << endl;
	
	return 0;
}
