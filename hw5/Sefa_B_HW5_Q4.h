#ifndef __BST_CLASS_H__
#define __BST_CLASS_H__

#include "Sefa_B_HW5_Q2.h"
#include <cstdlib> //Provides size_t


template<class Item>
class binarySearchTree{
	public:
		binarySearchTree(const Item& entry); /*NOTE this function will call createFirstNode so that we don't need to seperate functions.... Going to try if it works*/
		void addNode();
		void removeNode();
		bool searchNode(const Item& target) const;
		binarySearchTree<Item>* searchNode(const Item& target); /*Slides say to return node pointing to the element we want.. */
		/*These two just return the min/max node in the list.*/
		size_t minimum() const;
		size_t maximum() const;
		
	private: 
		binaryTree<Item> * tree_ptr;
		/*Don't need this, but going to add it just to have here*/
		size_t count; 

}

#include "Sefa_B_HW5_Q4.cpp"

#endif

