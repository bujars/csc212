#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

template<class Item>
class stack{
	public:
		stack(int init_capacity = 30){
			capacity = init_capacity;
			used = 0;
			data = new Item[capacity];
		}
		~stack();
		void print() const;
		void push(const Item& entry);
		size_t size() const{ return used;} /*Implemented here.*/
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
