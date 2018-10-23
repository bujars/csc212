#ifndef __QUEUE_CPP__
#define __QUEUE_CPP__

#include "Sefa_B_HW4_Q2.h"

template<class Item>
queue<Item>::queue(size_t init_cap){
	capacity = init_cap;
	data = new Item[capacity];
	count = 0;
	first = 0;
	last = -1;/*Because next indext gets the first index when want to start*/
	
}


template<class Item>
queue<Item>::~queue(){
	delete [] data;
	capacity = 0; 
	first = 0;
	last = -1;
	count = 0;
}

template<class Item>
queue<Item>::queue(const queue<Item>& source){
	capacity = source.capacity;
	count = source.count;
	first = source.first;
	last = source.last;
	size_t i = first;
	while(i!=last){
		data[i] = source.data[i];
		i = next_index(i);
	}
}

template<class Item>
bool queue<Item>::empty() const{
	return count == 0;
}

template<class Item>
Item queue<Item>::front() const {
	assert(!empty());
	return data[front];
}

//template<class Item>



#endif
