#include "stackLinkedList.h"

int main(){
	stack a;
	cout << a.isEmpty() << endl;
	a.push(20);
	a.push(30);
	a.push(40);
	a.print();
	cout << endl << endl <<a.top() << " " << a.size() << " " << endl << endl; 
	a.pop();
	a.print();
	cout << endl << endl <<a.top() << " " << a.size() << " " << endl << endl;
	return 0;
}
