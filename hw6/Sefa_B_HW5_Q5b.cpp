//#if 0
///*
#include <cstdlib>
#include <cassert>
#include <iostream>



using namespace std;
//*/

#include "Sefa_B_HW6_Q1.h"
/*NOTE NOTE NOTE NOTE NOTE This code is from HW5_Q5b.cpp*/
/*NOTE 11/30/18. These functions have been alterated to heapsort an array based on weights not just vertices */


/*NOTE these aren't template functions because they actually dont have anything to do with the heap. It as if constructing the heap itself. It just configures the current array so that its as a heap. Doesn't use heapClass. */
void makeHeap(int arr[], int weigh[], size_t size){
	/*heap<int> * heapArr = new heap<int>(size);
	for(size_t i = 0; i < size; i++){
		heapArr->addNode(arr[i]);
	}*/

	/*NOTE this is literally like add. The way the book is doing it is that it is teating heapsort as its own thing. Meaning that it just changes the arary thats given instead of actually making a heap as an array.*/
	size_t indexNew;
	for(size_t i = 1; i < size; i++){
		indexNew = i;
		while((indexNew>0) && (weigh[indexNew] > weigh[(indexNew-1)/2])){
			int tempArr = arr[indexNew];
			int tempWeigh = weigh[indexNew];
			weigh[indexNew] = weigh[(indexNew-1)/2];
			weigh[(indexNew-1)/2] = tempWeigh;
			arr[indexNew] = arr[(indexNew-1)/2];
			arr[(indexNew-1)/2] = tempArr;
			indexNew = (indexNew-1)/2;
		}
	}
}

/*This function is basically like delete, just moves larger child up, and root down.*/
void reheapify_down(int arr[], int weigh[], size_t size){
	size_t i = 0;
	if(size == 1){
		return;
	}
	/*While we are not a heap, and we have a child to swap with.*/
	while((i<size) && (2*i+1)<size){//&& ((2*i+1)<size && (2*i+2) < size)){
		/*Again like in delete, if */
		int tempWeigh = weigh[i];
		int tempArr = arr[i];
		if((2*i+2) >= size){ /*NOTE if our right side is too big, stop this loop.*/
			i = size;
		}
		else if((weigh[i] < weigh[2*i+1])&&(weigh[(2*i+1)]>=weigh[2*i+2])){
			arr[i] = arr[2*i+1];
			arr[2*i+1] = tempArr;
			weigh[i] = weigh[2*i+1];
			weigh[2*i+1] = tempWeigh;
			i = 2*i+1;
		}
		else if((arr[i]< arr[2*i+2]) && (arr[2*i+2] > arr[2*i+1])){
			arr[i] = arr[2*i+2];
			arr[2*i+2] = tempArr;
			weigh[i] = weigh[2*i+2];
			weigh[2*i+2] = tempWeigh;
			i = 2*i+2;
		}
		else{
			i = size;
		}
	}
				
}
							


void heapSort(int arr[], int weigh[], size_t size){
	size_t i;
	makeHeap(arr, weigh, size); /*Turn array into heap.*/
	/*for(size_t i = 0; i < size; i++){
		cout << arr[i] << endl;
	}*/
	i = size;
	while(i > 1){
		--i; /*Decrease index so its valid. Start from last.*/
		/*Swap root with last. */
		int tempArr = arr[0];
		int tempWeigh = weigh[0];
		arr[0] = arr[i]; 
		arr[i] = tempArr;
		weigh[0] = weigh[i];
		weigh[i] = tempWeigh;
		reheapify_down(arr, weigh, i); 
		/*Make sure max is always at the top by rearragning.*/
	}

}
//#endif


