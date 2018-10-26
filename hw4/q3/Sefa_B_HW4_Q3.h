#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

template<class Item>
class priority_queue{
	public:
		priority_queue(size_t init_cap= 5); /*NOTE decreased capacity to smaller testable value. change back to 30*/
		~priority_queue();
		priority_queue(const priority_queue<Item>& source);
		void operator=(const priority_queue<Item>& source);
		void pop();
		void push(const Item& entry, const int& priority);
		Item top() const;
		size_t size() const; /*{ return count; }*/
		bool empty() const;
		/* TO IMPLEMENT LATER */
		void swapPriorityQueues(priority_queue<Item>& source);
		void print();

	private:
		Item * data;
		int * priority;
		size_t first;
		size_t last;
		size_t count;
		size_t capacity;
		/* Helper Method */
		size_t next_index(size_t i){ return (i+1)%capacity;}
		
};


/*NOTE I AM MAKING PRIORITY TO BE INT. IT MAYBE CAN BE ITEM, BUT THAT DIDNT MAKE SENSE TO ME IF WE USE STRINGS AS ITEMS.*/

#include "Sefa_B_HW4_Q3.cpp"
#endif
