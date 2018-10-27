#include "Sefa_B_HW4_Q3.h"

int main(){
	priority_queue<int>a;
	a.push(1,1);
	a.push(2,1);
	a.push(3,2);
	a.push(4,2);
	a.pop();
	a.push(5,0);
	a.push(6,5);
	a.pop();
	a.push(7,0);
	/*solutin should be 3 4 1 2 5*/
	cout << "top " << a.top() << endl;	
	a.print();
	cout << a.size() << endl;
	return 0;
}
