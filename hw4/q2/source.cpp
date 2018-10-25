#include "Sefa_B_HW4_Q2.h"

int main(){

	queue<int>a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.print();
	cout << endl<< a.size() << endl << endl;

	cout << a.front() << endl;
	queue<int>b(a);
	cout << endl;
	b.print();
	//b = a;
	//b.print();
	
	//cout << endl;
	return 0;
}
