#ifndef __STACK_H__
#define __STACK_H__
#include <cassert>
#include <cstdlib>

template <class Item>
class stack{
	public:
		stack(size_t init_capacity = 30){
			capacity = init_capacity;
			used = 0;
			data = new Item[capacity];
		}
		~stack();
		stack(const stack<Item>& source);
		void operator =(const stack<Item>& source);
		void pop(); /*remove top item in stack*/
		void push(const Item& entry); /*Insert an item to top of stack*/
		bool isEmpty() const{ return used == 0;} /*Check if the stack is empty*/
		size_t size() const{ return used;} /*Return the number of items in the stack*/
		Item top() const; /*Get the top item*/


};





#include "Sefa_B_HW4_Q1.template"


#endif
