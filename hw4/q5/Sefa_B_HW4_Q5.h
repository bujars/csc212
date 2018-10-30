#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Sefa_B_HW4_Q2.h"

using namespace std;



template<class Item>
class stack{
	public:
		stack(size_t init_cap = 5);
		~stack();
		stack(const stack<Item>& source);
		void operator=(const stack<Item>& source);
		void push(const Item& entry);
		void pop();
		bool isEmpty() const;
		size_t size() const;
		Item top();
		void print();
	private:
		/*NOTE changed from pointers to standard to avoid having to write copy constructor/assignment operator.*/
		queue<Item> stackHolder;/* * stackHolder;*/
		queue<Item> stackTemp;/* * stackTemp;*/


};

#include "Sefa_B_HW4_Q5.cpp"

#endif
