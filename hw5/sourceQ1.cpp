#include "Sefa_B_HW5_Q1.h"

int main(){
	btNode<int> b(3);
	btNode<int> b2(1);
	btNode<int> b3(5);
	//b.set_left_ptr(&b2);
	//b.set_right_ptr(&b3);
	btNode<int> b4;
	btNode<int>b5(2, &b2, &b);
	b4 = b5;
	print(&b);
	print(&b2);
	print(&b3);
	print(&b4);
	b.set_left_ptr(&b2);
	cout << "Size b4 " << numNodesbT(&b4) << endl;
	cout << "Height b4 " << heightbT(&b4) << endl;
	cout << endl << endl << endl;
	cout << "Size b1 " << numNodesbT(&b) << endl;
	cout << "height b1  " << heightbT(&b) << endl;
	return 0;
}
