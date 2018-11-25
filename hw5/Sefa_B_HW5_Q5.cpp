#ifndef __HEAP_CLASS_CPP__
#define __HEAP_CLASS_CPP__

#include "Sefa_B_HW5_Q5.h"

#if 0
template<class Item>
heap<Item>::heap(const Item& firstEntry, size_t init_cap){
	/*heapData = new binaryTree<Item>(init_cap);
	heapData->createFirstNode(firstEntry);*/
	/*data = new Item[init_cap];
	capacity = init_cap;
	count = 0;*/

}
#endif


template<class Item>
heap<Item>::heap(size_t init_cap){
	heapData = new Item[init_cap];
	CAPACITY = init_cap;
	count = 0;
}

template<class Item>
void heap<Item>::addNode(const Item& entry){
	if(!(count<CAPACITY)){
		resize(CAPACITY*2);
	}
	heapData[count++] = entry; /*Count is incremented. */
	size_t i = count; /*Set i to the index of the last, will be used to keep track of which elements to swap*/
	while(i!=0 && (heapData[i]> heapData[(i-1)/2])){
			Item temp = heapData[i];
			heapData[i] = heapData[(i-1)/2];
			heapData[(i-1)/2] = temp;
			i = (i-1)/2; /*Keep swapping with parent until it gets to the spot it needs to.*/
	}



	/*
	 * Must check so many cases, the wya this works is that we only have track of current and right.... So as we add, once we fill up the left and right, we need to move up and then move over to the next left/ right
	 *
	 * */
}


template<class Item>
size_t heap<Item>::deleteNode(){
	assert(count > 0);
	size_t retVal = heapData[0];
	heapData[0] = heapData[--count];
	size_t i = 0; /*Set index to start*/
	while(i < count){
		Item temp = heapData[i];
		if(heapData[i] < heapData[2i+1]){
			heapData[i] = heapData[2i+1];
			heapData[2i+1] = temp;
		}
		else if(heapData[i]< heapData[2i+2]){
			heapData[i] = heapData[2i+2];
			heapData[2i+2] = temp;
		}
		else{
			i = count;
		}
	}
	return retVal;
}

template<class Item>
void heap<Item>::resize(const size_t& new_size){
	if(new_size == CAPACITY)
		return; /*This is saying, if what we want is already the same, dont do anything.*/
	if(new_size < count)
		return; /*This is saying that if we want something smaller than the entries, dont do it becuase we cant lose stuff.*/
	Item * newHeap = new Item[new_size];
	for(size_t i = 0; i < count; i++){
		newHeap[i] = heapData[i];
	}
	delete heapData;
	CAPACITY = new_size;
	heapData = newHeap;
}


template<class Item>
size_t heap<Item>::minimum(){
	assert(count > 0);
	size_t min = heapData[0];
	if(count == 1){
		return min;
	}
	for(size_t i = 1; i < count-1; i++){
		if(heapData[i] < heapData[i+1]){
			min = heapData[i];
		}
	}
	return min;
}


template<class Item>
size_t heap<Item>::maximum(){
	assert(count > 0);
	size_t max = heapData[0];
	if(count == 1){
		return max;
	}
	for(size_t i = 1; i < count-1; i++){
		if(heapData[i] > heapData[i+1]){
			max = heapData[i];
		}
	}
	return max;
}


#endif
