#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

template<class Item>
class stack{
	public:
		
		/*
		 * What: This function/constructor creates a stack.
		 * How: This funtion/constructor initialized all the member vaiables of the stack, creates a dynamic array for data, sets inital capacity, and used = 0.
		 * Precondition: N/A.
		 * Postcondition: A stack is created. 
		 * Worst Time Complexity: O(1)
		 */
		stack(int init_capacity = 30){
			capacity = init_capacity;
			used = 0;
			data = new Item[capacity];
		}
		~stack();
		void print() const;
		void push(const Item& entry);
		size_t size() const;
		bool isEmpty() const;
		void pop();
		stack(const stack& source);
		void operator=(const stack& source);
		Item top() const; 
		/*void swapStacks(stack& secondStack);*//*Note one paramter since its a member function and member must call it.*/
	private:
		Item * data;
		size_t used;
		size_t capacity;

};

template<class Item>
void swapStacks(stack<Item>& stack1, stack<Item>& stack2);


#include "Sefa_B_HW4_Q1.cpp"
#endif
