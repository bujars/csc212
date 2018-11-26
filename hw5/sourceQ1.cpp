#include "Sefa_B_HW5_Q5.h"

int main(){

	heap<int> * h = new heap<int>(5);
	h->addNode(1);
	cout <<"D"<< h->deleteNode() << endl;
	h->print();
	h->addNode(2);
	h->print();
	h->addNode(3);
	h->addNode(4);
	h->addNode(5);
	h->addNode(6);
	h->print();
	
	cout << "DELETEING " << endl;
	
	cout <<"D"<< h->deleteNode() << endl;
	h->print();
	cout <<"D"<< h->deleteNode() << endl;
	h->print();
	cout <<"D"<< h->deleteNode() << endl;
	h->print();
	cout <<"D"<< h->deleteNode() << endl;
	h->print();
	cout <<"D"<< h->deleteNode() << endl;
	h->print();
	
	//	cout <<"D"<< h->deleteNode() << endl;
	
	
//	cout << endl << h->minimum() << endl;
//	cout << endl << h->maximum() << endl;
	
	cout << endl;
	int arr[10] = {5,8,3,6,2,9,0,1,7,4};
	size_t size = 10;
	//int* sortedArr = heapSort(arr, size);
	//heapSort(arr,size);
	
	for(size_t i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;	
	
	return 0;


}







#if 0 

#include "Sefa_B_HW5_Q4.h"

int main(){
	binarySearchTree<int> * b = new binarySearchTree<int>(2);
	//b->addNode(3);
	//b->addNode(3);

	/*NOTE not really sure how searchNode will be tested honeslty. It is a btNode not really a binary tree so we cant do much with it. Like shift left or stuff like that.*/
	btNode<int> * c = b->searchNode(2);
	/*cout << "PRINTING C " << endl;*/
	/*assert(c !=NULL);*/
	/*cout << c->data();*/ /*NOTE this fails when there is nothing in the tree!!!!!!!!!*/
	/*cout << endl << endl;*/
	//cout << c == NULL << endl;
	//binarySearchTree<int> * c = NULL;
	//c->addNode(2);
	b->addNode(5);
	//b->printT();
	b->addNode(6);
	//b->printT();
	b->addNode(1);
	b->addNode(4);
	b->addNode(0);
	b->printT();

	btNode<int> * d = b->searchNode(0);




	/*Testing minimum, expecting 0.*/
	cout << "MINIMUM " << endl;
	btNode<int> * min = b->minimum(c);
	cout << min->data()<< endl<< endl;

	
	/*Testing maximum, expecting 0.*/
	cout << "MAXIMUM " << endl;
	btNode<int> * max = b->maximum(c);
	cout << max->data()<< endl<< endl;
	



	/*Testing transplant.......Will have to get back to honestly because not even sure how to create the trees and stuff....*/
	
	/*Testing delete.*/
	b->removeNode(d);



	binarySearchTree<int> * bst = new binarySearchTree<int>(100);
	bst->addNode(50);
	bst->addNode(200);
	bst->addNode(30);
	bst->addNode(60);
	bst->addNode(75);
	bst->addNode(210);
	bst->addNode(195);
	bst->printP();
	btNode<int> * s = bst->searchNode(60);
	cout << endl << endl  <<s->data() << endl << endl;
	bst->removeNode(s);
	bst->printP();


	return 0;


}









#endif




#if 0 

#include "Sefa_B_HW5_Q3.h"

int main(){
	
	/*NOTE, WHEN TESTING MUST MAKE SURE ITS A COMPLETE BINARY TREE OR YOU WILL GET ERRORS AS YOU ALREADY HAVE. */
	
	binaryTree<int> * b = new binaryTree<int>;
	b->createFirstNode(2);
	cout << "HAS PARENT " << b->hasParent() << endl;	
	cout << "DATA: " << b->retrieve() << endl;
	cout << "HASL " << b->hasLeft() << endl;
	cout << "HASR " << b-> hasRight() << endl;
	b->shiftToRoot(); 
	cout << "DATA: " << b->retrieve() << endl;
	/*b->shiftUp();*/ /*Works because of assertion of has parent.*/
	/*b->shiftLeft();
	b->shiftRight();*/
	b->addLeft(3);
	/** NOTE NOTE NOTE Added left here. Must make sure to add right so that its complete...thats becaue im shifting. If it was the end not requried to add right unless want full   **/	
	b->addRight(6);
	cout << "HASL " << b->hasLeft() << endl;
	cout << "HASR " << b-> hasRight() << endl;
	b->shiftLeft();
	cout << "HASL " << b->hasLeft() << endl;
	cout << "DATA: " << b->retrieve() << endl;
	cout << "HASR " << b-> hasRight() << endl;
	/*NOTE MUST HAD LEFT THEN RIGHT*/
	b->addLeft(7);
	b->addRight(5);
	cout << "HASL " << b->hasLeft() << endl;
	cout << "DATA: " << b->retrieve() << endl;
	cout << "HASR " << b-> hasRight() << endl;
	b->shiftRight();
	cout << "HASL " << b->hasLeft() << endl;
	cout << "DATA: " << b->retrieve() << endl;
	cout << "HASR " << b-> hasRight() << endl;
	cout << (b == NULL) << endl;
	binaryTree<int> c();
	return 0;
}



#endif




#if 0
#include "Sefa_B_HW5_Q2.h"
int main(){
	binaryTree<int> * b = new binaryTree<int>;
	binaryTree<int>* c(b);
	//c->print();
	/*b->addLeft(2);*/
	b->createFirstNode(2);
	b->addLeft(1);
	b->print();
#if 0
	
	cout << "SIZE " <<b ->size() << endl;
	cout << "HAS PARENT " << b->hasParent() << endl;
	cout << "HAS LEFT " <<b->hasLeft() << endl;
	cout << "HAS RIGHT "<<b->hasRight() << endl;
	cout << "RETRIEVE " <<b->retrieve() << endl;
	b->addRight(3);
	cout << "HAS RIGHT " <<b->hasRight() << endl;
	b->addLeft(10);
	cout << "HAS LEFT " << b->hasLeft()<<endl;
	//binaryTree<int> * bLeft = b->left();
	/*b->addLeft(5); //Works for the case of assertion. */
	
	/*I think to add, we must shift and then add? Not exactly sure but with the methods we have, thats the only thing we can do.*/
	
	binaryTree<int> *bP(b);
	cout<< "BP " << b->retrieve() << endl;
	
	b->shiftLeft();
	cout<< "BLEFT " << b->retrieve() << endl;
	cout << "HASBLEFT " << b->hasLeft() << endl;
	cout <<endl << endl <<"BRPARENT...T?... " << b->hasParent() << endl;
	b->addLeft(13);
	b->addRight(16);
	cout << "HASBLEFT " << b->hasLeft() << endl;
	//cout <<  "BLEFTRIGHT Before chainge" << b->retrieve() << endl
	b->shiftRight();
	cout <<  "BLEFTRIGHT " << b->retrieve() << endl;
	b->change(18);
	cout <<  "BLEFTRIGHTChange " << b->retrieve() << endl;
	//b->shiftToRoot();
	cout << "BR " << b->retrieve() << endl;
	cout <<endl << endl <<"BRPARENT...T?... " << b->hasParent() << endl;	
	
	//cout << (bP == NULL) << endl;
	//binaryTree<int> bD;
	//	cout << (bD == NULL) << endl;

	/*Attemping shiftingUp*/
	cout << endl << endl << "SHIFTING UP" << endl;
	b->shiftUp();
	cout << "HAS PARENT " << b->hasParent() << endl;
	cout << "HAS LEFT " <<b->hasLeft() << endl;
	cout << "HAS RIGHT "<<b->hasRight() << endl;
	cout << "RETRIEVE " <<b->retrieve() << endl;
	b->shiftUp();
	cout << "HAS PARENT " << b->hasParent() << endl;
	cout << "HAS LEFT " <<b->hasLeft() << endl;
	cout << "HAS RIGHT "<<b->hasRight() << endl;
	cout << "RETRIEVE " <<b->retrieve() << endl;
	/*
 	b->shiftUp();
	cout << "HAS PARENT " << b->hasParent() << endl;
	cout << "HAS LEFT " <<b->hasLeft() << endl;
	cout << "HAS RIGHT "<<b->hasRight() << endl;
	cout << "RETRIEVE " <<b->retrieve() << endl;
	*/

#endif

	btNode<int> * e = new btNode<int>;
	btNode<int> * f = new btNode<int>(2);
	btNode<int> * g = new btNode<int>(4);
	e->set_left_ptr(f);
	e->set_left_ptr(g);
	b->setRoot(e);
	b->print();


	return 0;
}



#endif







#if 0
#include "Sefa_B_HW5_Q1.h"

//#if 0
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
	
	btNode<int> * root = NULL;
	root = &b;
	//print(root);

//#if 0	
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
	cout << endl << endl<< "BEFORE" << endl;
	print(&a);
	cout << "AFTER" << endl;
	//clearbT(a);
	
	print(&a);
	cout << "ENDL" << endl<< endl;
//#endif

	btNode<int> * root_ptr = NULL;
	//root_ptr = &a;
	clearbT(root_ptr);


	/*Testing creating nodes the way copy does*/
	btNode<int> * r = new btNode<int>; /*Make a root with nothing.*/
	btNode<int> * r1L = new btNode<int>(1);
	btNode<int> * r1R = new btNode<int>(2);
	r->set_left_ptr(r1L);
	r->set_right_ptr(r1R);
	print(r->right());
	btNode<int> * cop = copybT(r);
	print(cop->right());
	clearbT(r);/*Works.*/
	print(r->left());
	return 0;
}
#endif






