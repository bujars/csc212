#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

template<class Item>
class queue{
	public:
		queue(size_t init_cap= 30);
		~queue();
		queue(const queue<Item>& source);
		void operator=(const queue<Item>& source);
		void pop();
		void push(const Item& entry);
		Item front() const;
		size_t size() const; /*{ return count; }*/
		bool empty() const;
		/* TO IMPLEMENT LATER */
		void swapQueues(queue<Item>& source);
	
	private:
		Item * data;
		size_t first;
		size_t last;
		size_t count;
		size_t capacity;
		/* Helper Method */
		size_t next_index(size_t i){ return (i+1)%capacity;}
		
};


#include "Sefa_B_HW4_Q2.cpp"
#endif
