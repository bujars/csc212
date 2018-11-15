#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__


#include "Sefa_B_HW5_Q3.h"

template<class Item>
binaryTree<Item>::binaryTree( ){
	CAPACITY = 30;
	/*count = 0;*/ /*Set this in createFirstNode*/
	treeData = new Item[CAPACITY];
	/*If need to set currentIndex = -1 because don't want user to access*/
}

template<class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){
	CAPACITY = source.CAPACITY;
	count = source.count;
	currentIndex = source.currentIndex;
	treeData = new Item[CAPACITY];
	for(size_t i = 0; i < CAPACITY; i++){
		treeData[i] = source.treeData[i];
	}
}

template<class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){
	count = 1;
	currentIndex = 0;
	treeData[currentIndex] = entry;
}

template<class Item>
binaryTree<Item>::~binaryTree(){
	delete [] treeData;
	CAPACITY = 0;
	count = 0;
	currentIndex = -1; /*Because don't want it pointing anywhere. Might have to set to 0. */
}

template<class Item>
size_t binaryTree<Item>::size() const{
	return count;
}

template<class Item>
Item binaryTree<Item>::retrieve( ) const{
	assert((size() > 0) && ((currentIndex >= 0) && (currentIndex < CAPACITY)));
	return treeData[currentIndex];
}

template<class Item>
void binaryTree<Item>::shiftToRoot(){
	assert((size() > 0) && ((currentIndex >= 0) && (currentIndex < CAPACITY)));
	currentIndex = 0; /*Just set currentIndex = 0 which points to root because root is always at [0]*/
}

template<class Item>
bool binaryTree<Item>::hasParent() const{
	assert((size() > 0) && ((currentIndex >= 0) && (currentIndex < CAPACITY)));
	return currentIndex != 0; /*Becuase if its at 0, it means that it is the root. So it must be any other value which would indicate it points to something else.*/
}

template<class Item>
void binaryTree<Item>::shiftUp(){
	assert(((size() > 0) && ((currentIndex >= 0) && (currentIndex < CAPACITY))) && hasParent()); /*this handles the whole size>0 and index stuff for current. NOTE this might not be the best approach wbecause this will fail in hasParent indtead of in this function...... OKay, ill just add the assert from hasParent here to be safe. */
	currentIndex = (currentIndex-1)/2; 
}


/*NOTE NOTE NOTE might need to make <= count... but count is always +1 so no. Just incase u have an error it could be at these two...*/
template<class Item>
bool binaryTree<Item>::hasLeft() const{
	assert((size() > 0) && ((currentIndex >= 0) && (currentIndex < CAPACITY)));
	return (2*currentIndex+1) < size(); 
	/*This is basically saying, we don't have anything at count, 
	 * then we should be fine because we actually have a child there. 
	 * Otherwsie we are empty and no left child exists there.*/
}

template<class Item>
bool binaryTree<Item>::hasRight() const{
	assert((size() > 0) && ((currentIndex >= 0) && (currentIndex < CAPACITY)));
	return (2*currentIndex+2) < size(); 
	/*This is basically saying, we don't have anything at count, 
	 * then we should be fine because we actually have a child there. 
	 * Otherwsie we are empty and no right child exists there.*/
}

template<class Item>
void binaryTree<Item>::shiftLeft(){
	assert(size() > 0 && hasLeft()); /*NOTE has left will have to take care of other factors. .. (preconditions)*/
	currentIndex = 2*currentIndex + 1;
}

template<class Item>
void binaryTree<Item>::shiftRight(){
	assert(size() > 0 && hasRight()); 
	/*NOTE has right will have to take care of other factors. .. (preconditions)*/
	currentIndex = 2*currentIndex + 2;
}

template<class Item>
void binaryTree<Item>::addLeft(const Item& entry){
	assert((size() > 0 && !hasLeft()) && (size() < CAPACITY));
	treeData[(2*currentIndex+1)] = entry;
	count++;
}

template<class Item>
void binaryTree<Item>::addRight(const Item& entry){
	assert((size() > 0 && !hasRight()) && (size() <CAPACITY));
	treeData[(2*currentIndex+2)] = entry;
	count++;
	cout << "HERE";
}

template<class Item>
void binaryTree<Item>::change(const Item& new_entry){
	assert(size() > 0);
	treeData[currentIndex] = new_entry;
}


/*Use size/count to see if you have already added a child or parent there........ Like if 2i+1/2 whatever is > count then dont do shit. */
#endif



