#ifndef __PRIORITY_QUEUE_CPP__
#define __PRIORITY_QUEUE_CPP__


#include "Sefa_B_HW4_Q3.h"

template<class Item>
priority_queue<Item>::priority_queue(size_t init_cap){
	capacity = init_cap;
	data = new Item[capacity];
	priority = new int[capacity];
	count = 0;
	first = 0;
	last = capacity-1;/*Because next indext gets the first index when want to start*/	
}
template<class Item>
priority_queue<Item>::~priority_queue(){
	delete [] data;
	delete [] priority;
	capacity = 0; 
	first = 0;
	last = -1;
	count = 0;
}

template<class Item>
priority_queue<Item>::priority_queue(const priority_queue<Item>& source){
	capacity = source.capacity;
	count = source.count;
	first = source.first;
	last = source.last;
	/*size_t i = first;*/
	data = new Item[capacity];
	priority = new int[capacity];
	/*while(i!=last+1){
	 * 		data[i] = source.data[i];
	 * 				i = next_index(i);
	 * 					}*/
	/*cout << "error here" << endl;*/
	/*NOTE it does not matter whats first/last....
	 * here we are just copying over the array....its the same thing*/
	/*UPDATE I might be wrong with the above, 
	 * because our array has just giberish in it.
	 * Not sure why it wont copy ovr but its giving 
	 * me an error to unwanted stuff.*/
	for(size_t i = 0; i < capacity; i++){
		data[i] = source.data[i];
	}
	for(size_t i =0; i < capacity; i++){
		priority[i] = source.priority[i];
	}
	/*cout << "error passed" << endl;*/
}

template<class Item>
void priority_queue<Item>::operator=(const priority_queue<Item>& source){
	if(this == &source)
		return;
	delete [] data;
	delete [] priority;
	capacity = source.capacity;
	data = new Item[capacity];
	priority = new int[capacity];
	first= source.first;
	last = source.last;
	count = source.count;
	size_t i = first;
	/*cout << i << endl;
	cout << capacity << endl;
	cout << last+1 << endl;*/
	/*while(i !=(last) && i<capacity){ //ISSUE IS ITS GOING PAST CAPACITY//
		//return;
		//cout << "Here" << endl;
		data[i] = source.data[i];
		i = next_index(i);
		cout << i << endl;
	}*/
	for(size_t i =0; i < capacity; i++){
		data[i] = source.data[i];
		priority[i] = source.priority[i];
	}
}




#endif
