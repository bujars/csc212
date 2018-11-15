#ifndef __BST_CLASS_CPP__
#define __BST_CLASS_CPP__

#include "Sefa_B_HW5_Q4.h"

template<class Item>
binarySearchTree<Item>::binarySearchTree(const Item& entry){
	tree_ptr = new binaryTree<Item>;
	tree_ptr->createFirstNode(entry);
	count = 1; /*Incase I do decide to use this...but it will be redundant because binaryTree aleady does it.*/
}

template<class Item>
void binarySearchTree<Item>::addNode(const Item& entry){
	if(tree_ptr == NULL){
		tree_ptr->createFirstNode(entry);
	}
	
	while(tree_ptr != NULL){
		if(tree_ptr->retrieve() < entry){
			if(!(tree_ptr->hasRight())){
				tree_ptr->addRight(entry);
			}
			else{
				tree_ptr->shiftRight();
			}
		}
		else{
			if(!(tree_ptr->hasLeft())){
				tree_ptr->addLeft(entry);
			}
			else{
				tree_ptr->shiftLeft();
			}
		}
	}
	/*
	while(tree_ptr->hasLeft() || tree_ptr->hasRight()){
		if(tree_ptr->retrieve() < entry){
			tree_ptr->shiftRightt()
		}
		else(tree_ptr->shiftLeft());
	}*/
}

template<class Item>
binarySearchTree<Item>* binarySearchTree<Item>::searchNode(const Item& target){
	bool found = false;
	binaryTree<Item> * retPtr = NULL;
	/* 4 cases
	 * 1. CurrentNode = target, return
	 * 2. Target is to the left of the tree, and we have a left there.
	 * 3. Target is to the right of the tree, and we hav e a right there.
	 * 4. Else nothing is possible and return false
	 * */
	while(!found){
		if(tree_ptr->retrieve() < target && tree_ptr->hasRight()){
			tree_ptr->shiftRight();
		}
		else if(tree_ptr->retrieve() > target && tree_ptr->hasLeft()){
			tree_ptr->shiftLeft();
		}
		else if(tree_ptr->retrieve() == target){
			retPtr = tree_ptr;
			found = true;
		}
		else{
			found = true;
		}
	}
	/*Set our pointer back to the root, that way we always can start from there.*/
	tree_ptr->shiftToRoot();
	return retPtr;

}

template<class Item>
void binarySearchTree<Item>::operator=(const binarySearchTree<Item>& source){
	if(this == &source){
		return;
	}
	//tree

}
#endif
