#ifndef __HEAP_CLASS_H__
#define __HEAP_CLASS_H__

#include "Sefa_B_HW5_Q3.h"
#include <cstdlib> //Provides size_t

template<class Item>
class heap{
	public:
		heap(size_t init_capcity = 30);
		void addNode(const Item& entry);
		size_t deleteNode(); /*Just deletes the highest node, the root node. */
		size_t searchNode(const Item& target); 
		/*Note here I am just returning index of where the node would be*/
		size_t minimum();
		size_t maximum();
		void resize(const size_t& new_size);
	private:
		/*binaryTree<int> * heapData;*/
		/*size_t capacity; */
		/*NOTE binaryTree handles all the size etc and asserting, etc.*/
		Item * heapData;
		size_t CAPACITY;
		size_t count;

};



#include "Sefa_B_HW5_Q5.cpp"

#endif



