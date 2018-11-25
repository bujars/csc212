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
	size_t i = count-1; /*Set i to the index of the last, will be used to keep track of which elements to swap*/
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
	cout << endl;
	cout << "RETVAL " << retVal<<endl;
	cout << "LAST" << heapData[count-1] << endl;
	cout << endl;
	heapData[0] = heapData[--count];
	if(count == 1){
		return retVal;
	}
	size_t i = 0; /*Set index to start*/
	while((i < count)){ //&& ((2*i+1) >= count && (2*i+2) >= count)){
		Item temp = heapData[i];
		/*NOTE it must be swapped with the larger child. I will have it go to the left if the two chilren are equal.*/
		if((heapData[i] < heapData[2*i+1]) && (heapData[2*i+1] >= heapData[2*i+2])){
			heapData[i] = heapData[2*i+1];
			heapData[2*i+1] = temp;
			i = 2*i+1;
		}
		else if((heapData[i]< heapData[2*i+2]) && (heapData[2*i+2] > heapData[2*i+1])){
			heapData[i] = heapData[2*i+2];
			heapData[2*i+2] = temp;
			i = 2*i+2;
		}
		else{
			i = count;
		}

		if((2*i+1) >= count && (2*i+2) >= count){
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
	for(size_t i = 1; i < count; i++){
		if(heapData[i] < min){
			min = heapData[i];
		}
	}
	return min;
}

/*NOTE, max is in the root.... But just did this way to be safe if i have any wrrors. */
template<class Item>
size_t heap<Item>::maximum(){
	assert(count > 0);
	size_t max = heapData[0];
	if(count == 1){
		return max;
	}
	for(size_t i = 1; i < count; i++){
		if(heapData[i] > max){
			max = heapData[i];
		}
	}
	return max;
}


/*NOTE, if my heap works as it should, maximum would do the same thing... because the property of the heap is that the max is always at the root.......
 * 
 * Added later, note forgot that delete returns the value it deletes. So, I don't really need this.
 * */
template<class Item>
size_t heap<Item>::root(){
	assert(count>0);
	return heapData[0];

}



template<class Item>
void heap<Item>::print(){
	for(size_t i = 0; i < count; i++){
		cout << heapData[i] << " ";
	}
	cout <<endl;

}



/*To Do a heapsort, we need three functions
 * 1. The heapsort functon itself, which returns a sorted array via heaps.
 * 2. Make heap, which makes and returns a heap based on an given array and size.(This just bascially goes through the array and adds it to a heap and returns the heap)
 * 3. Re-heapification-> basically when we "delete" a value from a heap, we need to resort that heap. 
 *
 * By looking at part 3, we might be able to escape make heap... This is because we only need to build it once, and we can use the same heap over and over again (assuming that this is all done in the heap class.) Because when we re-heapify, we are only going through the list, or in a sense using the delte function on the heap.....
 * Yea?? Why are we not just adding and deleting, it doesn't make sense to me why we need make heap/reheapify....... The way I see from the textbook is because they aren't actually losing the heap...but still doens't make sense to me....
 * */
template<class Item>
Item* heapSort(const Item arr[], size_t size){
	assert(size>0); /*That we actually have something, else we can't really do anything...*/
	heap<Item> * heapArr= new heap<Item>(size);
	/*Make a head of the array..*/
	for(size_t i = 0; i < size; i++){
		heapArr->addNode(arr[i]);
	}
	Item* sortedArr = new Item[size];
	for(size_t i = size-1; i >0; --i){
		sortedArr[i] = heapArr->deleteNode();
	}
	/*delete heapArr;*/
	return sortedArr;

	
}







#endif
