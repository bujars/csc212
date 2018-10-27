#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Sefa_B_HW4_Q1.h"
using namespace std;

template<class Item>
class queue{
	public:
		queue(size_t init_cap = 5);
		~queue();
		queue(const queue<Item>& source);
		void operator=(const queue<Item>&source);
		void push(const Item& entry);
		void pop();
		size_t size() const;
		bool empty() const;
		Item front() const;
		void swapQueues(queue<Item>& source);
	private:
		/*Item * data;
		size_t first;
		size_t last;
		size_t count;
		size_t capacity;*/
		stack<Item> * queueHolder;
		stack<Item> * queueTemp;
};

#include "Sefa_B_HW4_Q4.cpp"
#endif

