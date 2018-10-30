#include "Sefa_B_HW4_Q5.h"

int main(){
	stack<int>a;
	stack<int>b;
	stack<int>c(a);
	b = c;
	bool aEm = c.isEmpty();
	cout << aEm << endl;
	cout << a.size() << endl;
	a.push(20);
	cout << a.top() << endl << endl;
	a.print();
	cout << endl << endl;
	a.push(30);
	cout << a.top() << endl;
	cout << endl << endl;
	a.print();
	cout << endl << endl;
	a.push(40);
	cout << a.top() << endl;
	cout << endl << endl;
	a.print();
	cout << endl << endl;
	a.push(50);
	cout << a.top() << endl;
	cout << endl << endl;
	a.print();
	cout << endl << endl;
	a.push(60);
	cout << a.top() << endl;
	cout << endl << endl;
	a.print();
	cout << endl << endl;
	a.push(40);
	cout << a.top() << endl;
	cout << endl << endl;
	a.print();
	cout << endl << endl;
	cout << endl << endl;
	
	a.print();
	a.pop();
	cout << endl << endl <<  a.top() << endl;
	return 0;
}
