#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__
#include "Sefa_B_HW6_Q2.h"

template<class Item>
graph<Item>::graph(const size_t init_cap){
	CAPACITY = init_cap;
	labels = new Item[CAPACITY];
	//list = new node<int>(CAPACITY);
	list = new node<Item>[CAPACITY];
	for(size_t i = 0; i < CAPACITY; i++){
		list[i] = new node<Item>();
	}
	numOfVertices = 0;

}

template<class Item>
graph<Item>::~graph(){
	delete list;
	delete labels;
	CAPACITY = 0;
	numOfVertices = 0;
}


template<class Item>
void graph<Item>::addVertex(const Item& label){
	/*Assume for now enough capcity. Not sure How I would transfer over an array of nodes.....list copy???? */
	list[numOfVertices] = new node<int>(numOfVertices, NULL);
	labels[numOfVertices] = label;
	numOfVertices++;
}

template<class Item>
void graph<Item>::print(){
	for(size_t i = 0; i < numOfVertices; i++){
		cout << list[i].data() << endl;
	}
}

#endif
