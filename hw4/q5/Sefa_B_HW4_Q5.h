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
		stack();
		~stack();
		stack(const stack<Item>& source);
		void operator=(const stack<Item>& source);
		void push(const Item& entry);
		void pop();
		bool isEmpty() const;
		size_t size() const;
		Item top() const;
	private:
		queue<Item> * stackHolder;
		queue<Item> * stackTemp;


};

#include "Sefa_B_HW4_Q5.cpp"

#endif
