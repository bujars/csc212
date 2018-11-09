#ifndef __BTNODE_CPP__
#define __BTNODE_CPP__
#include "Sefa_B_HW5_Q1.h"
	
template<class Item>
btNode<Item>::btNode( const Item& init_data,
					  btNode<Item> * init_left, 
					  btNode<Item> * init_right){
	data_field = init_data;
	left_ptr = init_left;
	right_ptr = init_right;
}

template<class Item>
btNode<Item>::~btNode(){

/*NOTE deconstructor is not working. Not exactly sure why.*/

#if 0
	/*Should essentially call list clear????? --> Not sure how unless the argument or ptr is this? */
	delete left_ptr;
	delete right_ptr;
	data_field = 0;
	left_ptr = NULL;
	right_ptr = NULL;
	/*delete this;
	data_field = 0;
	left_ptr = NULL;
	right_ptr = NULL;*/
#endif
}


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
	if(root_ptr == NULL){
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





#endif

