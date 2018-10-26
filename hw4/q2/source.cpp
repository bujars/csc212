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
	queue<int>b(a);
	cout << endl;
	//b.print();
	//b = a;
	b.print();
	
	queue<int> d;
	cout << endl << endl << "what's this?" << endl;
	b = d;
	//d = b;
	b.print();

	//cout << endl;
	return 0;
}
