#include "Sefa_B_HW4_Q4.h"

int main(){
	queue<int> a;
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
	cout << a.front() << endl << endl;
	a.print();	
	cout << endl<< a.size() << endl;
	
	queue<int>b;
	b.push(11);
	b.push(12);
	b.push(13);
	b.push(14);
	b.push(15);
#if 0
	//a = b;
	cout << endl;
	b.print();
	queue<int>c(a);
	cout << endl << endl;
	c.print();
	cout << endl;
#endif

	return 0;
}
