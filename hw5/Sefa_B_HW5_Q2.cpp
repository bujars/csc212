#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__



#include "Sefa_B_HW5_Q2.h"

template<class Item>
binaryTree<Item>::binaryTree(){
	currentNode = NULL;
	rootNode = NULL;
	/*parentNode = NULL;*/
}

template<class Item>
binaryTree<Item>::~binaryTree(){
	//delete currentNode;
	//delete rootNode;
	/*delete parentNode;*/
	/*Delete all and reset to NULL*/
	/*Must go through the list and remove everything. Notice clearbT sets rootNode to NULL, so no need to worry about it.*/
	clearbT(rootNode);
	/*Just get rid of current next.*/
	delete currentNode;
	currentNode = NULL;
	//rootNode = NULL;
	/*parentNode = NULL;*/
}

template<class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){
	rootNode = copybT(source); /*This copies our list*/
	/*Just copy over these nodes.No, this wont work. because root poiner will hold the whole list right, but those nodes wont match if we just make seperat copies. */

	/*Set it to rootNode or the intial. Must change somehow to be the current/parnet if user tries to make a copy from somewhere down in the list.. Not sure how I can iterate through and then set those specfic nodes. But its something needed to be done--> hecne why im writing these thoughts down. */
	currentNode = rootNode;
	/*parentNode = rootNode;*/ 
}

template<class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){
	//root_ptr =
	assert((currentNode == NULL) && (rootNode == NULL));
	currentNode = new btNode<Item>(entry);
	rootNode = currentNode;
	/*
	 * rootNode = currentNode;
	 * parentNode = currentNode; //NOTE I think this remains NULL until a child is added. 
	 * */
}

template<class Item>
bool binaryTree<Item>::hasParent() const{
	if(rootNode == NULL || currentNode==rootNode || !(size() >0)){ /*The side part may be redundant*/
		return false;
	}
	return true;

	/*OLD::Parent node is initalized to the pointer above current. 
	 * But when the fist node is inserted, parent remains as null. 
	 * Parent only changes when we move left or right. */

	/*NOTE not sure if I actually would need to iterate to find a parnet.
	 * They way I did it was if the root isn't NULL (meaning we have a root), 
	 * and if the currentNode is not the same as the root, so it's somewhere down
	 * the line, then it must have a parent.*/

}

/*originally had left==NULL which would mean no child. Had to change this.*/
template<class Item>
bool binaryTree<Item>::hasLeft() const {
	/*assert(size() > 0);*/
	return ((currentNode->left() != NULL) && (size()>0));
}

template<class Item>
bool binaryTree<Item>::hasRight() const{
	/*assert(size() > 0);*/
	return ((currentNode->right() != NULL) && (size() > 0));
}


template<class Item>
size_t binaryTree<Item>::size() const{
	/*NOT sure if I was to assert here, as numNodesbT should handle empty case.*/
	assert(rootNode != NULL);
	return numNodesbT(rootNode); 
	/*NOTE want in the tree. Current node can be somewhere down in the tree.*/
		/*numNodesbT(currentNode);*/
}

template<class Item>
Item binaryTree<Item>::retrieve() const{
	assert(this->size()>0);
	return currentNode->data();
}

template<class Item>
void binaryTree<Item>::addRight(const Item& entry){
	/*NOTE this could be done using an if statement and just return. But I would rather it halt the program so that the user can know that they cannot perform this command and must change it*/
	assert((size() >0) && (!hasRight()));
	btNode<Item> * newRight = new btNode<Item>(entry);
	currentNode->set_right_ptr(newRight);
}

template<class Item>
void binaryTree<Item>::addLeft(const Item& entry){
	assert((size()>0) && (!hasLeft())); 
	/*NOTE like addRight, might need to change to if.*/
	btNode<Item> * newLeft = new btNode<Item>(entry);
	currentNode->set_left_ptr(newLeft);
}

/*template<class Item>
void binaryTree<Item>

*/
template<class Item>
void binaryTree<Item>::shiftLeft(){
	assert(hasLeft() && (size()>0));/*Make sure we have a left child to move to. Again asserting just to be safe.*/
	currentNode = currentNode->left();
}

template<class Item>
void binaryTree<Item>::shiftRight(){
	assert(hasRight() && (size() > 0));
	currentNode = currentNode->right();
}

template<class Item>
void binaryTree<Item>::change(const Item& entry){
	assert((currentNode !=NULL) && (size() > 0)); /*Make sure we have a currentNode*/
	currentNode->set_data(entry); /*Change entry as needed.*/

}

template<class Item>
void binaryTree<Item>::print(){
	assert(currentNode!=NULL && size()>0);
	cout << currentNode->data() << endl;
	//cout << currentNode->left()->data();
}

#endif
