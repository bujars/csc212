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


template<class Item>
bool priority_queue<Item>::empty() const{
	return count == 0;
}

/*NOTE plays the same role since we order them with prioirty.*/
template<class Item>
Item priority_queue<Item>::top() const {
	assert(!empty());
	return data[first];
}

template<class Item>
void priority_queue<Item>::push(const Item& entry, const int& prior){
	/*Remember this is a circular array, 
	 * so stuff goes in the front if its empty. 
	 * But we also need to check if count is filled, 
	 * if that is the case, we need to create a new 
	 * array which shifts everything over and it is resized. */
	if(count >= capacity){ /*NOTE CANNOT USE size() or it 
							 will fail because size==count at start.*/
		Item * biggerData = new Item[++capacity]; /*New array. 
											NOTE capacity was also incremented 
											here.*/
		int * biggerPriority = new int[capacity]; /*BC capacity was incremented*/
		for(size_t i = 0; i < count; i++){ /*Transferring everything over...*/
			biggerData[i] = data[i];
			biggerPriority[i] = priority[i];
		}
		delete [] data;
		delete [] priority;
		this->data = biggerData;
		this->priority = biggerPriority;
	}
	/*THIS CODE IS THE SAME FOR ALL CASES: APPEND TO THE END SINCE FIFO. */
	/*cout << "CAP " << capacity  << endl << endl<< "LAST " << last << endl;
	 * 	cout << (last+1) % capacity << endl;*/
	/*NOTE, we need to shift everything accordingly to prority*/
	last = next_index(last);
	/*cout << "NEW LAST " << last << endl;
	 * 	cout << "ENTRY " << entry << endl << endl << endl;
	 * 		cout << "BEFORE ADD " << data[last] << endl;*/
	data[last] = entry;
	priority[last] = prior;
	count++;
}

/*NOTE this stays the same as queue because first holds the place with the most priority. */
template<class Item>
void priority_queue<Item>::pop(){
	/*Check if queue is empty*/
	assert(!empty());
	/*THIS IS FIFO, thus, must get rid of first, NOT LAST*/
	first = next_index(first);
	count--;
	/*Do i need to check if first becomes last?? Does it matter? No?*/

}

template<class Item>
size_t priority_queue<Item>::size() const{
		return count;
}




template<class Item>
void priority_queue<Item>::print(){
	size_t index = 0;
	for(size_t i = 0; i < capacity; i++){
		
		cout << "Printing entry then priority" << endl;
		cout << data[i] << " " << priority[i] <<endl;
	}
}






#endif
