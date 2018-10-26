#ifndef __QUEUE_CPP__
#define __QUEUE_CPP__

#include "Sefa_B_HW4_Q2.h"

template<class Item>
queue<Item>::queue(size_t init_cap){
	capacity = init_cap;
	data = new Item[capacity];
	count = 0;
	first = 0;
	last = capacity-1;/*Because next indext gets the first index when want to start*/	
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
	/*size_t i = first;*/
	data = new Item[capacity];
	/*while(i!=last+1){
		data[i] = source.data[i];
		i = next_index(i);
	}*/
	/*cout << "error here" << endl;*/
	/*NOTE it does not matter whats first/last....here we are just copying over the array....its the same thing*/
	/*UPDATE I might be wrong with the above, because our array has just giberish in it. Not sure why it wont copy ovr but its giving me an error to unwanted stuff.*/
	for(size_t i = 0; i < capacity; i++){
		data[i] = source.data[i];
	}
	cout << "error passed" << endl;
}

template<class Item>
void queue<Item>::operator=(const queue<Item>& source){
	if(this == &source)
		return;
	delete [] data;
	capacity = source.capacity;
	data = new Item[capacity];
	first= source.first;
	last = source.last;
	count = source.count;
	size_t i = first;
	//cout << i << endl;
	//cout << capacity << endl;
	//cout << last+1 << endl;
	/*while(i !=(last) && i<capacity){ //ISSUE IS ITS GOING PAST CAPACITY//
		//return;
		//cout << "Here" << endl;
		data[i] = source.data[i];
		i = next_index(i);
		cout << i << endl;
	}*/

	for(size_t i =0; i < capacity; i++){
		data[i] = source.data[i];
	}
}


template<class Item>
bool queue<Item>::empty() const{
	return count == 0;
}

template<class Item>
Item queue<Item>::front() const {
	assert(!empty());
	return data[first];
}

template<class Item>
void queue<Item>::push(const Item& entry){

	last = next_index(last);
	data[last] = entry;
	count++;
}

template<class Item>
size_t queue<Item>::size() const{
	return count;
}



template<class Item>
void queue<Item>::print(){
	size_t index = 0;
	for(size_t i = 0; i < count; i++){
		index = next_index(first+i) -1; 
		cout << data[index] << endl;
	}
#if 0
	while(i <= (last)){ /*Has to be last+1 becasue last holds the last item, is not necessarily the size. Or can do <=last but then that would work if say last was in the fron and i/first was in the back.*/
		cout << data[i] << endl;
		i=next_index(i);
	}
#endif

	/*NOTE: This function was taken from mycodeschool github file. 
	 * Was having trouble with infinite loop and resorted to trying 
	 * someone elses code just for testing purposes. All credit for print function given to them.*/

}



#endif
