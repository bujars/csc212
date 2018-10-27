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
	/*cout << "error passed" << endl;*/
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
	/*Remember this is a circular array, so stuff goes in the front if its empty. But we also need to check if count is filled, if that is the case, we need to create a new array which shifts everything over and it is resized. */
	if(count >= capacity){ /*NOTE CANNOT USE size() or it will fail because size==count at start.*/
		Item * bigger = new Item[++capacity]; /*New array. NOTE capacity was also incremented here.*/
		for(size_t i = 0; i < count; i++){ /*Transferring everything over...*/
			bigger[i] = data[i];
		}
		delete [] data;
		this->data = bigger;
	}
	/*THIS CODE IS THE SAME FOR ALL CASES: APPEND TO THE END SINCE FIFO. */
	/*cout << "CAP " << capacity  << endl << endl<< "LAST " << last << endl;
	cout << (last+1) % capacity << endl;*/
	last = next_index(last);
	/*cout << "NEW LAST " << last << endl;
	cout << "ENTRY " << entry << endl << endl << endl;
	cout << "BEFORE ADD " << data[last] << endl;*/
	data[last] = entry;
	count++;
#if 0
	
	cout << "WHAT SHOULD BE: " << data[last] << endl;	
	/*count++;*/
	/*I beleive I handled all cases...*/
	for(int i = 0; i < count; i++){
		cout << data[i] << " ";
	}
	cout << endl;

#endif
}

template<class Item>
void queue<Item>::pop(){
/*Check if queue is empty*/
	assert(!empty());
	/*THIS IS FIFO, thus, must get rid of first, NOT LAST*/
	first = next_index(first);
	count--;
	/*Do i need to check if first becomes last?? Does it matter? No?*/

}




template<class Item>
size_t queue<Item>::size() const{
	return count;
}



template<class Item>
void queue<Item>::print(){
	size_t index = 0;
	
	/*cout << "COUNT " << count << endl;
	for(size_t i = 0; i < count; i++){
		index = next_index(first+i) -1;
		cout << "INDEX: " <<index << endl;
		cout << this->data[index] << endl;
	}
*/
	for(size_t i = 0; i < size(); i++){
		cout << data[i] << endl;
	}

	/*priting in order trial*/
/*	cout << "TRYING TO PRINT IN ORDER:" << endl;
	size_t next_last = next_index(last);
	size_t i = first;
	while(i != last){
		cout << data [i] << " ";
	}
	cout << "DONE" << endl;
*/

#if 0
	while(i <= (last)){ /*Has to be last+1 becasue last holds the last item, is not necessarily the size. Or can do <=last but then that would work if say last was in the fron and i/first was in the back.*/
		cout << data[i] << endl;
		i=next_index(i);
	}
//#endif

	/*NOTE: This function was taken from mycodeschool github file. 
	 * Was having trouble with infinite loop and resorted to trying 
	 * someone elses code just for testing purposes. All credit for print function given to them.*/
#endif
}


template<class Item>
void queue<Item>::swapQueues(queue<Item>& source){
	if(this == &source)/*If they are the same stacks, dont do anything*/
		return;
	queue<Item> tempThis(capacity);
	/*Might be able to use copy constructor and say this queue... and then just do assignments between the two.*/
	/*NOTE keep having trouble with index of first/last so will just trasnfer every single element, even though this is not efficent at all.*/
	for(size_t i = 0; i < capacity; i++){
		tempThis.data[i] = data[i];
	}
	tempThis.first = first;
	tempThis.last = last;
	tempThis.count = count;
	delete [] data; 
	capacity = source.capacity;
	data = new Item[capacity];
	first = source.first;
	last = source.last;
	count = source.count;
	for(size_t i = 0; i < capacity; i++){
		data[i] = source.data[i];
	}
	source = tempThis;
}





#endif
