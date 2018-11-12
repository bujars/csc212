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
}


template<class Item>
size_t binaryTree<Item>::size() const{
	return currentNode.numOfNodes();
}

#endif
