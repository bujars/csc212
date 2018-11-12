#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__



#include "Sefa_B_HW5_Q2.h"

template<class Item>
binaryTree<Item>::binaryTree(){
	currentNode = NULL;
	rootNode = NULL;
	parentNode = NULL;
}

template<class Item>
binaryTree<Item>::~binaryTree(){
	delete currentNode;
	delete rootNode;
	delete parentNode;
	/*Delete all and reset to NULL*/
	currentNode = NULL;
	rootNode = NULL;
	parentNode = NULL;
}

template<class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){
	rootNode = copybT(source); /*This copies our list*/
	/*Just copy over these nodes.No, this wont work. because root poiner will hold the whole list right, but those nodes wont match if we just make seperat copies. */

	/*Set it to rootNode or the intial. Must change somehow to be the current/parnet if user tries to make a copy from somewhere down in the list.. Not sure how I can iterate through and then set those specfic nodes. But its something needed to be done--> hecne why im writing these thoughts down. */
	currentNode = rootNode;
	parentNode = rootNode; 
}

template<class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){
	//root_ptr =
	currentNode = new btNode<Item>(entry);
	/*
	 * rootNode = currentNode;
	 * parentNode = currentNode; //NOTE I think this remains NULL until a child is added. 
	 * */
}

template<class Item>
bool binaryTree<Item>::hasParent() const{
	return (parentNode == NULL); /*Parent node is initalized to the pointer above current. But when the fist node is inserted, parent remains as null. Parent only changes when we move left or right. */
}

template<class Item>
bool binaryTree<Item>::hasLeft() const {
	return (currentNode->left() == NULL);
}

template<class Item>
bool binaryTree<Item>::hasRight() const{
	return (currentNode->right() == NULL);
}


template<class Item>
size_t binaryTree<Item>::size() const{
	return numNodesbT(currentNode);
}

template<class Item>
void binaryTree<Item>::print(){
	cout << currentNode->data() << endl;
	//cout << currentNode->left()->data();
}

#endif
