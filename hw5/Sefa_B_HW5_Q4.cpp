#ifndef __BST_CLASS_CPP__
#define __BST_CLASS_CPP__

#include "Sefa_B_HW5_Q4.h"

template<class Item>
binarySearchTree<Item>::binarySearchTree(const Item& entry){
	tree_ptr = binaryTree<Item>();
	tree_ptr.createFirstNode(entry);
	count = 1; /*Incase I do decide to use this...but it will be redundant because binaryTree aleady does it.*/
}

/*NOTE professo timmy said to return a btNode pointer... Not sure why but okay? I would much rather return something like a binaryTreePointer which keeps track of everything like parent, left right etc..... Lets see because this poitner is just pointing to that node, not necessarily the node itself.*/
template<class Item>
btNode<Item>* binarySearchTree<Item>::searchNode(const Item& target){
	/*cout << "T " << target << endl;*/
	btNode<Item> * retNode = NULL;
	/*cout << "RET " << retNode << endl;*/
	if(target == tree_ptr.retrieve()){
		retNode = tree_ptr.retrieveNode();
		return retNode;
	}
	bool found = false;
	while(!found){
		/*cout << "found : " << found << endl;*/
		if(target == tree_ptr.retrieve()){
			retNode = tree_ptr.retrieveNode();
			found = true;
			//tree_ptr.shiftToRoot();
			//return retNode;
		}
		else if(target < tree_ptr.retrieve() && tree_ptr.hasLeft()){
			tree_ptr.shiftLeft();
		}
		else if(target > tree_ptr.retrieve() && tree_ptr.hasRight()){
			tree_ptr.shiftRight();
		}
		else{
			found = true;
		}
	}
	/*cout << "RETTT " << retNode << endl;*/
 	tree_ptr.shiftToRoot();
	return retNode;
}

template<class Item>
void binarySearchTree<Item>::addNode(const Item& entry){
	if(this == NULL){
		tree_ptr = binaryTree<Item>();
		tree_ptr.createFirstNode(entry);
		count = 1; /*Incase I do decide to use this...but it will be redundant because binaryTree aleady does it.*/
	}
/*Ideally it would be good to use searchNode so that u can find where it must go....but of course no.*/
	if((tree_ptr.size() == 0)){ /*IF we have no tree at all. If our size is 0. Originally had it == NULL but that didn't work. Then i though of comparing it to the root, and no function for that. SO last resort was just to see if we could have an empty lsit by size = 0.*/
		tree_ptr.createFirstNode(entry);
		return;
	}
	/*cout <<"Printing entry in add " <<entry << endl;	*/
	bool found = false;
	while(!found){
		/*cout << "Tree current " << tree_ptr.retrieve() << endl;*/
		if(entry <= tree_ptr.retrieve() && tree_ptr.hasLeft()){
			tree_ptr.shiftLeft();
		}
		else if(entry > tree_ptr.retrieve() && tree_ptr.hasRight()){
			tree_ptr.shiftRight();
		}
		else{
			found = true;
		}
	}
	if(entry <= tree_ptr.retrieve()){
		tree_ptr.addLeft(entry);
	}
	else{
		tree_ptr.addRight(entry);
	}
	/*Then set the node back to the top. Since we shifted everywhere and we always want it on top*/
	tree_ptr.shiftToRoot();

#if 0
	if(tree_ptr == NULL){
		tree_ptr.createFirstNode(entry);
	}
	
	while(tree_ptr != NULL){
		if(tree_ptr.retrieve() < entry){
			if(!(tree_ptr.hasRight())){
				tree_ptr.addRight(entry);
			}
			else{
				tree_ptr.shiftRight();
			}
		}
		else{
			if(!(tree_ptr.hasLeft())){
				tree_ptr.addLeft(entry);
			}
			else{
				tree_ptr.shiftLeft();
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

#endif
}

#if 0
template<class Item>
btNode<Item>* binarySearchTree<Item>::minimum(){
	btNode<Item>* minPtr = tree_ptr.retrieveNode();
	while(tree_ptr.hasLeft()){
		tree_ptr.shiftLeft();
		minPtr = tree_ptr.retrieveNode();
	}
	tree_ptr.shiftToRoot();
	return minPtr;

}

template<class Item>
btNode<Item>* binarySearchTree<Item>::maximum(){
	btNode<Item>* maxPtr = tree_ptr.retrieveNode();
	while(tree_ptr.hasRight()){
		tree_ptr.shiftRight();
		maxPtr = tree_ptr.retrieveNode();
	}
	tree_ptr.shiftToRoot();
	return maxPtr;
}
#endif




/*NOTE need to rewrite min/max because those ^ cannot be used in delete...
 *
 * In addition. Note I do not check any cases such as is the node actually in the tree and other stuff...... okay i should do that because I was only given pesduo code....
 *
 * */
template<class Item>
btNode<Item>* binarySearchTree<Item>::minimum(btNode<Item>* node){
	assert(node!=NULL);
	btNode<Item>* found = searchNode(node->data());
	assert(found !=NULL);
	btNode<Item>* minPtr = node;
	btNode<Item>* iterator = node;
	while(iterator->left() !=NULL){
		//minPtr = iterator;
		iterator = iterator->left();
		minPtr = iterator;
	}
	return minPtr;
}

template<class Item>
btNode<Item>* binarySearchTree<Item>::maximum(btNode<Item>* node){
	assert(node!=NULL);
	btNode<Item>* found = searchNode(node->data());
	assert(found !=NULL);
	btNode<Item>* maxPtr = node;
	btNode<Item>* iterator = node;
	while(iterator->right() !=NULL){
		//maxPtr = iterator;
		iterator = iterator->right();
		maxPtr = iterator;
	}
	return maxPtr;
}





/* The point of the transplant function is to replace the 
 * old subtree with the new subtree on the overall Binary search tree.
 *
 *  Cases: 
 *  1. If oldTree has no parent, then just set newTree to the root...
 *  because it would mean oldTree was the root.
 *  2. If oldtree was the left child of the tree, make newTree the left.
 *  3. If oldtree was the right child, make newTree the right,
 *
 *  This function will be utalized in delete. because it will be used in cases of shifting the tree.
 *
 * */

template<class Item>
void binarySearchTree<Item>::transplant(btNode<Item>* oldTree, 
										btNode<Item>* newTree){
	if(oldTree->parent() == NULL){
		tree_ptr.setRoot(newTree);
	}
	else if(oldTree == (oldTree->parent())->left()){
		(oldTree->parent())->set_left_ptr(newTree);
	}
	else{
		(oldTree->parent())->set_right_ptr(newTree);
	}
	if(newTree!=NULL){
		newTree->set_parent(oldTree->parent());
	}
}




template<class Item>
void binarySearchTree<Item>::removeNode(btNode<Item>* nodeZ){
	assert(nodeZ!=NULL); /*Make sure we are given a node*/
	btNode<Item>* found = searchNode(nodeZ->data()); /*Make sure this node is in the tree*/
	assert(found !=NULL);
	if(nodeZ->left() == NULL && nodeZ->right() == NULL){
		/*delete found;*/ /*This doesnt make snese because found is not from the tree. How would I be able to find the pointer from the tree and delete it???*/

		/*My guess would be to just set the current node data = 0, and have its parent just point to NULL?????*/
		(nodeZ->parent())->set_parent(NULL);
		nodeZ->set_data(0);
		/*delete nodeZ;*/ /*Dont think this will actually do anything...*/
	}
	/*If we have only the right child, shift it to current position.*/
	if(nodeZ->left() == NULL){
		transplant(nodeZ, nodeZ->right());
	}
	else if(nodeZ->right() == NULL){ /*else if only left, shift to current*/
		transplant(nodeZ, nodeZ->left());
	}
	else{
		/*If we have two children, here is the hard part. We must first find the new smallest maximum, or sucessor */
		btNode<Item>* nodeZSuccessor = minimum(nodeZ->right());
		if(nodeZSuccessor->parent() != nodeZ){
			transplant(nodeZSuccessor, nodeZSuccessor->right());
			nodeZSuccessor->set_right_ptr(nodeZ->right());
			(nodeZSuccessor->right())->set_parent(nodeZSuccessor);
		}
		transplant(nodeZ, nodeZSuccessor);
		nodeZSuccessor->set_left_ptr(nodeZ->left());
		(nodeZSuccessor->left())->set_parent(nodeZSuccessor);
	}

}





template<class Item>
void binarySearchTree<Item>::printT(){
	tree_ptr.print();
	/*cout << "FUCK" << endl;*/
	cout << "SIZE " <<tree_ptr.size()<< endl;
	/*cout << "LOL" << endl;*/
	tree_ptr.shiftRight();
	tree_ptr.print();
	
	cout << "Size " << tree_ptr.size() << endl;
	tree_ptr.shiftRight();
	tree_ptr.print();

	/*Send it all the way back up or it will mess everything up.*/
	tree_ptr.shiftToRoot();
}




template<class Item>
void binarySearchTree<Item>::printP(){
	btNode<Item> * bt = searchNode(100);
	inOrderTraversal(bt, print<int>);

}








/*Doesn't work*/
#if 0
template<class Item>
btNode<Item>* binarySearchTree<Item>::searchNode(const Item& target){
	bool found = false;
	btNode<Item> * retPtr = NULL;
	/* 4 cases
	 * 1. CurrentNode = target, return
	 * 2. Target is to the left of the tree, and we have a left there.
	 * 3. Target is to the right of the tree, and we hav e a right there.
	 * 4. Else nothing is possible and return false
	 * */:
	while(!found){
		if(tree_ptr.retrieve() < target && tree_ptr.hasRight()){
			tree_ptr.shiftRight();
		}
		else if(tree_ptr.retrieve() > target && tree_ptr.hasLeft()){
			tree_ptr.shiftLeft();
		}
		else if(tree_ptr.retrieve() == target){
			retPtr = tree_ptr.currentNode;
			found = true;
		}
		else{
			found = true;
		}
	}
	/*Set our pointer back to the root, that way we always can start from there.*/
	tree_ptr.shiftToRoot();
	return retPtr;

}
#endif
/*
template<class Item>
void binarySearchTree<Item>::operator=(const binarySearchTree<Item>& source){
	if(this == &source){
		return;
	}
	//tree

}*/
#endif
