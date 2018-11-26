#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__
#include "Sefa_B_HW6_Q1.h"

template<class Item>
graph<Item>::graph(const size_t& init_cap){
	CAPACITY = init_cap;
	edges = new int*[CAPACITY];
	for(size_t i = 0; i < CAPACITY; i++){
		edges[i] = new int[CAPACITY];
	}
	labels = new Item[CAPACITY];
	numOfVertices = 0;

}

template<class Item>
graph<Item>::~graph(){
	delete labels;
	for(size_t i = 0; i < CAPACITY; i++){
		delete edges[i];
	}
	delete edges;
	numOfVertices = 0;
	CAPACITY = 0;
}

template<class Item>
graph<Item>::graph(const graph<Item>& source){
	CAPACITY = source.CAPACITY;
	edges = new int*[CAPACITY];
	for(size_t i = 0; i < CAPACITY; i++){
		edges[i] = new int[CAPACITY];
	}
	labels = new Item[CAPACITY];
	numOfVertices = source.numOfVertices;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < CAPACITY; j++){
			edges[i][j] = source.edges[i][j];
		}
	}
	/*Playing it safe...but can do this in the loop above*/
	for(size_t i = 0; i < CAPACITY; i++){
		labels[i] = source.labels[i];
	}
}

template<class Item>
void graph<Item>::operator=(const graph<Item>& source){
	/* If its the same thing, don't do anything. */
	if(this == &source){
		return;
	}
	CAPACITY = source.CAPACITY;
	edges = new int*[CAPACITY];
	for(size_t i = 0; i < CAPACITY; i++){
		edges[i] = new int[CAPACITY];
	}
	labels = new Item[CAPACITY];
	numOfVertices = source.numOfVertices;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < CAPACITY; j++){
			edges[i][j] = source.edges[i][j];
		}
	}
	/*Playing it safe...but can do this in the loop above*/
	for(size_t i = 0; i < CAPACITY; i++){
		labels[i] = source.labels[i];
	}
}

/* NOTE argument arr. This is because we don't know which array/double array we are changing.*/
template<class Item>
void graph<Item>::resize(Item * arr ,const size_t& new_size){
	if(new_size == CAPACITY)
		return; /*This is saying, if what we want is already the same, dont do anything.*/
	if(new_size < numOfVertices)
		return; /*This is saying that if we want something smaller than the entries, dont do it becuase we cant lose stuff.*/
	Item * newArr = new Item[new_size];
	for(size_t i = 0; i < numOfVertices; i++){
		newArr[i] = arr[i];
	}
	delete arr;
	/*NOTE HERE that capacity changes, thus, must keep track of old capacity, because you will be changing may different arrays.*/
	CAPACITY = new_size;
	arr = newArr;
}

template<class Item>
void graph<Item>::addVertex(const Item& label){
	/*If we don't have enough space, 
	 * we need to increase the capacity for everything*/
	size_t oldCap = CAPACITY;
	if(!(numOfVertices < oldCap)){
		/*Resize every column....possibly row...forgot but i think its column.*/
		for(size_t i = 0; i < oldCap; i++){
			resize(edges[i], oldCap*2);
			CAPACITY = oldCap;
		}
		resize(edges, oldCap*2);
		CAPACITY = oldCap;
		resize(labels, oldCap);
		/*NOTE, now capacity doesn't need to be changed once more because now we need to make sure its the good way.*/
	}
	/*If everything is resized as needed, now just append everything to the end.*/
	labels[numOfVertices++] = label;
	/*Don't really have to do anything to the edges here because by default they are set to 0. If not, then wuld have to go through that row/column and set to 0.*/
}

template<class Item>
void graph<Item>::addEdge(const size_t& source, const size_t& target){
	assert((numOfVertices > 0) && ((source < numOfVertices) && (target < numOfVertices)));
	edges[source][target]++;
}

template<class Item>
size_t graph<Item>::numEdges(const size_t& source, const size_t& target){
	assert((numOfVertices > 0) && ((source < numOfVertices) && (target < numOfVertices)));
	return edges[source][target];
}

template<class Item>
bool graph<Item>::isConnected(const size_t& source, const size_t& target){
	assert((numOfVertices > 0) && ((source < numOfVertices) && (target < numOfVertices)));
	return numEdges(source, target) != 0;
}

template<class Item>
void graph<Item>::removeEdge(const size_t& source, const size_t& target){
	assert((numOfVertices > 0) && ((source < numOfVertices) && (target < numOfVertices)));
	assert(isConnected(source, target));
	edges[source][target]--;
}

#endif

