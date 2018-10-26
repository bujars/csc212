#include "Sefa_B_HW4_Q1.h"

int main(){
	stack<int> s;
	cout << s.isEmpty() << endl;
	/*cout << s.top() << endl;	*/
	cout << endl << endl;
	s.push(2);
	s.push(4);
	s.push(6);
	s.print();
	cout << endl << endl; 	
	cout << s.isEmpty() << endl;
	cout << s.size() << endl;
	/*s.pop();
	
	cout << endl << endl;
	s.print();
	
	cout << endl << endl;
	cout << s.isEmpty() << endl;
	cout << s.size() << endl;
	//s.pop();
	//s.pop();
	
	cout << endl << endl << endl;
	
	s.print();

	cout << endl << endl;
	cout << s.isEmpty() << endl;
	//s.print();
	cout << s.size() << endl;
	*/
	stack<int> d(s);
	cout << endl << endl;
	d.print();
	
	cout << endl << endl;
	stack<int> a;
	a.push(1);
	a.push(3);
	a.push(5);
	a.print();
	cout << endl << endl << a.size() << endl <<  a.isEmpty() << endl << endl;
	s = a; 
	s.print();
	cout << endl << endl; 
	s = d;
	s.print();

	cout << endl << endl << s.top() << endl << endl;	
	/*s.pop();*/
#if 0
	cout << "SWAP" << endl;
	a.print();
	s.print();
	cout << endl << endl;
	/*s.swapStacks(a);*/
	a.print();
	cout << endl << endl;
	s.print();
#endif

	/*s.pop();
	s.pop();
	s.pop();
	a.pop();
	a.pop();
	a.pop();*//*Tested swaping if one of the lists was empty*/
	cout << "TESTING SWAP" << endl;
	cout << "Printing S" << endl;
	s.print();
	cout << endl;
	cout << "Printing A" << endl;
	a.print(); 
	cout << endl; 
	s.swapStacks(a);
	cout << "Printing S" << endl;
	s.print();
	cout << endl;
	cout << "Printing A" << endl;
	a.print();



	return 0;

}
