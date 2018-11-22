#ifndef __BTNODE_CPP__
#define __BTNODE_CPP__
#include "Sefa_B_HW5_Q1.h"
	
template<class Item>
btNode<Item>::btNode( const Item& init_data,
					  btNode<Item> * init_left, 
					  btNode<Item> * init_right,
					  btNode<Item> * init_parent){
	data_field = init_data;
	left_ptr = init_left;
	right_ptr = init_right;
	parent_ptr = init_parent;
}

template<class Item>
btNode<Item>::btNode(const btNode<Item>* source){
	/*NOTE source is a root pointer, so we would want to utalize copy() which would go in and copy every single field....but how???*/
	
	/* data_field = source.data_field;
	 * left_ptr = source.left_ptr;
	 * right_ptr =source.right_ptr; */

}

template<class Item>
void btNode<Item>::operator =(const btNode<Item>* source){
	if(this==source) return;
}




//#if 0
template<class Item>
btNode<Item>::~btNode(){

/*NOTE deconstructor is not working. Not exactly sure why.*/

//#if 0
	/*Should essentially call list clear????? --> Not sure how unless the argument or ptr is this? */
	//delete left_ptr;
	//delete right_ptr;
	data_field = 0;
	//left_ptr = NULL;
	//right_ptr = NULL;
	/*delete this;
	data_field = 0;
	left_ptr = NULL;
	right_ptr = NULL;*/
//#endif
}

//#endif

/*NOTE this function is called in the traversal ones. Only the current node is printed because the traversal ones recursively go through the list calling this specific function. */
template<class Item>
void print(const btNode<Item>* root_ptr){
	if(root_ptr ==NULL ) return; /*NOTE not sure if supposed to be assert.*/
	cout << root_ptr->data() << endl; /*Using endl so prints going down. 
									   Can change to " "   */
}

/*I do not beleive this works like print. I think this is just a recursive function that alulates the number of nodes.*/
template<class Item>
size_t numNodesbT(const btNode<Item>* root_ptr){
	/*Recursively go down the left, and then the right and everytime we hit a leaf, return 0. Sum up each recursive call.*/
	if(root_ptr == NULL){ /*NOT sure if I would need to assert here and just halt program. */
		return 0;
	}
//#if 0
	/*NOTE this is my solution. Test it out and see if it works. If it does not, use the textbook which is simpler.*/
	size_t count = 1;
	count = count + numNodesbT(root_ptr->left()); /*Keep track of current count in the recursive call, and then the count = 1 is alays set to 1 in each call but still kept track of. This is so we add 1 each time we find a node.*/
	count = count + numNodesbT(root_ptr->right());
	/*cout << "DAAATAAA " << root_ptr->data() << endl;*/
	return count;
//#endif
//return 1 + numNodesbT(root_ptr->left()) + numNodesbT(root_ptr->right());

	/*Textbook: return 1 + numNodesbT(root_ptr.left()) + numNodesbT(root_ptr.right()); */
}

template<class Item>
size_t heightbT(const btNode<Item>* root_ptr){
	if(root_ptr==NULL){
		return 0;
		
	}
	/*cout << "DATA" << root_ptr->data() << endl;*/
	size_t leftCount = 0;
	size_t rightCount = 0;
	leftCount = leftCount + 1 + heightbT(root_ptr->left());
	//cout << "printing left " <<root_ptr->data() << endl;
	rightCount = rightCount + 1 + heightbT(root_ptr->right());
	//cout << "printing right " << root_ptr->data() << endl;
	if(leftCount > rightCount)
		return leftCount;
	return rightCount;
}

/* NOTE: (left) Root (right) */
template<class Item, class Process>
void inOrderTraversal(const btNode<Item>* root_ptr, Process f){
	if(root_ptr == NULL){
		return;
	}
	/* Go through left side first. */
	inOrderTraversal(root_ptr->left(), f);
	f(root_ptr);
	inOrderTraversal(root_ptr->right(),f);

}

template<class Item, class Process>
void preOrderTraversal(const btNode<Item>* root_ptr, Process f){
	if(root_ptr == NULL){
		return;
	}
	/* Go through root first. */
	f(root_ptr);
	preOrderTraversal(root_ptr->left(), f);
	preOrderTraversal(root_ptr->right(),f);

}

template<class Item, class Process>
void postOrderTraversal(const btNode<Item>* root_ptr, Process f){
	if(root_ptr == NULL){
		return;
	}
	/* Go through left side first. */
	postOrderTraversal(root_ptr->left(), f);
	postOrderTraversal(root_ptr->right(),f);
	f(root_ptr);
}

template<class Item, class Process>
void backWardInOrderTraversal(const btNode<Item>* root_ptr, Process f){
	if(root_ptr == NULL){
		return;
	}
	/* Go through right side first. */
	backWardInOrderTraversal(root_ptr->right(), f);
	f(root_ptr);
	backWardInOrderTraversal(root_ptr->left(),f);

}

template<class Item>
void clearbT(btNode<Item>*& root_ptr){
	/*If the current pointer is null, do nothing*/
	if(root_ptr == NULL) return;
	/*Iterate down to every single leaf and delete that pointer and reset it to null, and set its data to 0.*/
	btNode<Item>* child;
	btNode<Item>* parent;
	child = root_ptr->left();
	clearbT(child); /*go all the way to left.*/
	child = root_ptr->right();
	clearbT(child); /*go all the way to the right.*/
	parent = root_ptr->parent();
	clearbT(parent);
	/* I am not sure if the parent is supposed to be cleared, but doesn't seem to present any issues. */

	
	//root_ptr->set_data(0);
	delete root_ptr;
	//root_ptr = NULL;
	//delete parent_ptr;
	//parent_ptr = NULL;
}

template<class Item>
btNode<Item>* copybT(btNode<Item>* root_ptr){
 /*Must copy everything from leaf working way up.*/
	/*Base case is always if ptr is null.*/
	if(root_ptr == NULL){
		return NULL; /*Since our return type is a pointer we must return null*/
	}
	/*When copying a tree, start with leafs. Luckily, can utalize the constructors*/
	btNode<Item> * left_ptr; /*Declare the nodes that will be used as links for the new root.*/
	btNode<Item> * right_ptr;
	btNode<Item> * parent_ptr;
	left_ptr = copybT(root_ptr->left()); /*Note we must always save the left becasue copybT returns a ptr*/
	right_ptr = copybT(root_ptr->right());
	parent_ptr = copybT(root_ptr->parent()); /*NOT really sure what this is supposed to do, if it even does anything at all.*/
	return new btNode<Item>(root_ptr->data(), left_ptr, right_ptr, parent_ptr); /*Return a new node of this item.*/
	//parent_ptr = root_ptr->parent();
}

#endif

