#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__



#include "Sefa_B_HW5_Q2.h"

template<class Item>
binaryTree<Item>::binaryTree(){
	currentNode = NULL;
	rootNode = NULL;
	count = 0;
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
	count = 0;
	//rootNode = NULL;
	/*parentNode = NULL;*/
}

template<class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){
	rootNode = copybT(source); /*This copies our list*/
	/*Just copy over these nodes.No, this wont work. because root poiner will hold the whole list right, but those nodes wont match if we just make seperat copies. */

	/*Set it to rootNode or the intial. Must change somehow to be the current/parnet if user tries to make a copy from somewhere down in the list.. Not sure how I can iterate through and then set those specfic nodes. But its something needed to be done--> hecne why im writing these thoughts down. */
	currentNode = rootNode;
	count = 0;
	/*parentNode = rootNode;*/ 
}

template<class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){
	//root_ptr =
	assert((currentNode == NULL) && (rootNode == NULL));
	currentNode = new btNode<Item>(entry);
	rootNode = currentNode;
	count = 1;
	/*
	 *
	 * rootNode = currentNode;
	 * parentNode = currentNode; //NOTE I think this remains NULL until a child is added. 
	 * */
}

template<class Item>
bool binaryTree<Item>::hasParent() const{
#if 0
	if(rootNode == NULL || currentNode==rootNode || !(size() >0)){ /*The side part may be redundant*/
		return false;
	}
	return true;
#endif
	/*OLD::Parent node is initalized to the pointer above current. 
	 * But when the fist node is inserted, parent remains as null. 
	 * Parent only changes when we move left or right. */

	/*NOTE not sure if I actually would need to iterate to find a parnet.
	 * They way I did it was if the root isn't NULL (meaning we have a root), 
	 * and if the currentNode is not the same as the root, so it's somewhere down
	 * the line, then it must have a parent.*/
	/*cout <<"UGHHHH " << rootNode->data() << endl;
	cout << "FUCCCCCCCCK      "<<rootNode->parent() << endl;*/
	return (currentNode->parent() != NULL) && size()>0;

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
	/*assert(rootNode != NULL);*//*THIS line is handled by count*/
	return count;
	/*numNodesbT(rootNode); */
	/*NOTE want in the tree. Current node can be somewhere down in the tree.*/
		/*numNodesbT(currentNode);*/
}

template<class Item>
Item binaryTree<Item>::retrieve() const{
	assert(this->size()>0);
	return currentNode->data();
}

template<class Item>
btNode<Item>* binaryTree<Item>::retrieveNode(){
	assert(this->size()>0); //&& hasParent());
	return currentNode;/*currentNode->parent();*/ /*NOTE not sure why I had parent here....Hope it doesn't mess any function. Changing because need current for q4. */
}



template<class Item>
void binaryTree<Item>::addRight(const Item& entry){
	/*NOTE this could be done using an if statement and just return. But I would rather it halt the program so that the user can know that they cannot perform this command and must change it*/
	assert((size() >0) && (!hasRight()));
	/*btNode<Item> *root = rootNode;*/
	btNode<Item> * newRight = new btNode<Item>(entry, NULL, NULL, currentNode);
	currentNode->set_right_ptr(newRight);
	count++;
}

template<class Item>
void binaryTree<Item>::addLeft(const Item& entry){
	assert((size()>0) && (!hasLeft())); 
	/*NOTE like addRight, might need to change to if.*/
	/*NOTE NOTE NOTE NOTE NOTE  here is where I added the parentNode to each new child......... Origianlly had in shift..see comments tehe*/
	btNode<Item> * newLeft = new btNode<Item>(entry,NULL,NULL, currentNode);
	currentNode->set_left_ptr(newLeft);
	count++;
}

/*template<class Item>
void binaryTree<Item>

*/
template<class Item>
void binaryTree<Item>::shiftLeft(){
	assert(hasLeft() && (size()>0));/*Make sure we have a left child to move to. Again asserting just to be safe.*/
	
	
	/*NOTE NOTE NOTE I for some reason thought of adding parent here but why would i add parent when I move...just add the parent when you create the child in the constructor duh...*/


	/*btNode<Item> * currPos = currentNode;*/
	currentNode = currentNode->left();
	/*currentNode->setParent(currPos);*/
}

template<class Item>
void binaryTree<Item>::shiftRight(){
	assert(hasRight() && (size() > 0));
	/*btNode<Item> * currPos = currentNode;*/
	currentNode = currentNode->right();
	/*currentNode->setParent(currPos);*/
}

template<class Item>
void binaryTree<Item>::change(const Item& entry){
	assert((currentNode !=NULL) && (size() > 0)); /*Make sure we have a currentNode*/
	currentNode->set_data(entry); /*Change entry as needed.*/

}

template<class Item>
void binaryTree<Item>::shiftToRoot(){
	assert(size()>0);
	currentNode = rootNode;
}

template<class Item>
void binaryTree<Item>::shiftUp(){
#if 0
/*Make sure we have a root ptr, make sure it isnt == to current, make sure hasPrent is true....recursively iterate until we find the pointer in which its child is == to current, then return that pointer*/
	assert((size() > 0) && hasParent());
	binaryTree<Item> * parent; 
	binaryTree<Item> * root = rootNode; 
	binaryTree<Item>* rootLeft = rootNode;
	binaryTree<Item>* rootRight = rootNode;
	if(rootNode->hasLeft()){
		rootLeft->shiftLeft(); 
	}
	if(rootLeft == currentNode){
		
	}
	if(rootNode->hasRight()){
		rootRight->shiftRight();
	}
	
//	btNode<Item> * parent;
	

	/*while(shift->left!=curent while shiftRight != current)
		call function again */
#endif

	/* NOTE adding parent node simplifies the function. */
	assert(size()>0 && hasParent());
	currentNode = currentNode->parent(); /*set the currentNode to the parent of the node. If its the root, or nothing, it does nothing. */


}


template<class Item>
void binaryTree<Item>::print(){
	assert(currentNode!=NULL);
	/*if(currentNode != NULL){*/
	cout << currentNode->data() << endl;
	//cout << currentNode->left()->data();*/
#if 0
	/*if(root_ptr == NULL){
			return;
						}*/
			/* Go through left side first. */
		print(currentNode->left());
		cout << currentNode->data << endl;
		print(currentNode->right());
	}*/
#endif
}

#endif
