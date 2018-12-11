#ifndef __BTNODE_H__
#define __BTNODE_H__

#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

template<class Item>
class btNode{
	public:
		/*NOTE must add parent pointer if decide to use it.*/
		btNode( const Item& init_data = Item(),
				btNode<Item>* init_left = NULL, 
				btNode<Item>* init_right = NULL,
				btNode<Item>* init_parent = NULL);
		btNode(const btNode<Item>* root_Ptr); /*Construcut a copy tree. Call list copy*/
		~btNode(); /*Deconstructor*/
		void operator=(const btNode<Item>* root_ptr);/*Assignment operator since non-static memory*/
		void set_data(const Item& entry){ data_field = entry;}
		void set_left_ptr(btNode<Item>* new_left){left_ptr = new_left;}
		void set_right_ptr(btNode<Item>* new_right){right_ptr = new_right;}
		void set_parent(btNode<Item>* new_parent){parent_ptr = new_parent;} /*Again implement this only if deciding to use parent*/
		bool isLeaf() const{
			return (left_ptr == NULL) && (right_ptr == NULL);
		}/*returns if left_ptr and right_ptr == NULL. Must check if there is a pointer though? If we pass a root?*/
		Item data(){return data_field;} /*NOTE if do Item& and remove const, data can be altered with this function*/
		const Item data() const{return data_field;}/*Constant get Data function for constant trees.*/
		btNode<Item>* left() { return left_ptr;}
		btNode<Item>* right() { return right_ptr;}
		btNode<Item>* parent() { return parent_ptr;}
		const btNode<Item>* left() const { return left_ptr;}
		const btNode<Item>* right() const { return right_ptr;}
		const btNode<Item>* parent() const {return parent_ptr;}

		/*Self added this function just to return count.*/
		/*size_t numNodesbT() const{ return count;}*/ /*NOTE we need a non-member funciton for num_of_nodes*/
	private:
		/*Every binary tree points to its left and right child*/
		btNode<Item>* parent_ptr;
		btNode<Item>* left_ptr; 
		btNode<Item>* right_ptr;
		/*To keep track of the data*/
		Item data_field; 
		/*TO Keep track of the number of nodes in the binary tree.
		 * Not necessarily needed but can help.*/
		/*size_t count;*/ /*Not necessary at all confirmed 12/10 because we dont actually really add here and have to keep track of it, if that makes sense. Here are just pointers. In q2 you would have size because there its important to know how many you added and what not*/
		/*Note sure if I will use this, 
		 * but may be helpful for Binary Search Tree Q3.*/
		/*btNode<Item>* parent_ptr;*/
};

#if 0
/*NOTE the Process class. This will allow me to now use functions */
template<class Item, class Process>
#endif

/*Functions for traversals. NOTE 4 different kind of traversals.
 * I beleive these are the ones that utalize process meaning 
 * that they should be able to print, copy, etc in a speific traversal.*/

/* NOTE: (left) Root (right) */
template<class Item, class Process>
void inOrderTraversal(const btNode<Item>* root_ptr, Process f);

/* NOTE Root (left) (right) */
template<class Item, class Process>
void preOrderTraversal(const btNode<Item>* root_ptr, Process f);

/* NOTE (left) (right) Root */
template<class Item, class Process>
void postOrderTraversal(const btNode<Item>* root_ptr, Process f);

/* NOTE (right) Root (left) */
template<class Item, class Process>
void backWardInOrderTraversal(const btNode<Item>* root_ptr, Process f);

template<class Item>
void print(const btNode<Item> * root_ptr);

/*Returns a "new" root pointer.*/
template<class Item>
btNode<Item>* copybT(const btNode<Item> * root_ptr);

/* Clears a tree by roomving all children first. 
 * Done recuriley. Check if leaf, if so remove all levt then all right, 
 * then move back up. 
 * NOTE how its not const and *& because we are altering the pointer.*/
template<class Item>
void clearbT(btNode<Item>*& root_ptr);

/*Recurvily go through the list and return 1 + every leaf you get so that 
 * total would be 1+1+1+1+....*/
template<class Item>
size_t numNodesbT(const btNode<Item>* root_ptr);


/*Traverse the most you can left/right, 
 * and compare that value and keep storing the highest value you get the return.
 * Somewhat similar to sizebT, values juse held differently. */
template<class Item>
size_t heightbT(const btNode<Item>*root_ptr);



#include "Sefa_B_HW5_Q1.cpp"


#endif
