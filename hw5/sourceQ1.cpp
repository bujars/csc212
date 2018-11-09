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
	cout << "NumNodes b4 " << numNodesbT(&b4) << endl;
	cout << "Height b4 " << heightbT(&b4) << endl;
	cout << endl << endl << endl;
	cout << "NumNodes b1 " << numNodesbT(&b) << endl;
	cout << "height b1  " << heightbT(&b) << endl;
	
	cout << endl << endl << endl;
	cout << "Attempting to make tree that i saw online, the image look in notes." << endl;
	/*Root*/
	btNode<int>a(25);
	/*Left subtree*/
	btNode<int>a1(15);
	btNode<int>a2(10);
	btNode<int>a3(22);
	btNode<int>a4(4);
	btNode<int>a5(12);
	btNode<int>a6(18);
	btNode<int>a7(24);
	/*Right*/
	btNode<int>a8(50);
	btNode<int>a9(35);
	btNode<int>a10(70);
	btNode<int>a11(31);
	btNode<int>a12(44);
	btNode<int>a13(66);
	btNode<int>a14(90);
	a.set_left_ptr(&a1);
	a.set_right_ptr(&a8);
	a1.set_left_ptr(&a2);
	a1.set_right_ptr(&a3);
	a2.set_left_ptr(&a4);
	a2.set_right_ptr(&a5);
	a3.set_left_ptr(&a6);
	a3.set_right_ptr(&a7);
	a8.set_left_ptr(&a9);
	a8.set_right_ptr(&a10);
	a9.set_left_ptr(&a11);
	a9.set_right_ptr(&a12);
	a10.set_left_ptr(&a13);
	a10.set_right_ptr(&a14);
	
	cout << endl << endl << endl;
	cout << "NumNodes a " << numNodesbT(&a) << endl;
	cout << "height a  " << heightbT(&a) << endl;		
	cout << endl << endl << endl;
	cout<< "INORDER: " << endl;
	inOrderTraversal(&a, print<int>);
	cout << endl << endl << "PREORDER "<< endl;
	preOrderTraversal(&a, print<int>);
	cout << endl << endl << "POSTORDER " << endl;
	postOrderTraversal(&a, print<int>);
	cout << endl << endl << "BACKWARD " << endl;
	backWardInOrderTraversal(&a,print<int>);
	cout << endl << endl;

	return 0;
}
