#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__
#include "Sefa_B_HW6_Q2.h"

template<class Item>
graph<Item>::graph(const size_t init_cap){
	CAPACITY = init_cap;
	labels = new Item[CAPACITY];
	//list = new node<int>(CAPACITY);
	
	/* "A dynamic 2D array is basically an arry of pointers to arrays" 
	 * So, first declare an array of the type that it will be pointing too with capacity.
	 * then declare each pointer in the array to whatever it need be, here its nodes. */
	
	list = new node<int>*[CAPACITY];
	/*for(size_t i = 0; i < CAPACITY; i++){
		list[i] = new node<Item>();
	}*/ /*I think this is supposed to be set in addVertex because making a new node makes the head basically....*/
	numOfVertices = 0;

}

template<class Item>
graph<Item>::~graph(){
	//delete list;
	/*Go through the list and clear out all nodes.*/
	for(size_t i =0; i< CAPACITY; i++){
		list_clear(list[i]);
	}
	/*delete the array of the list.*/
	delete [] list;
	delete labels;
	CAPACITY = 0;
	numOfVertices = 0;
}

template<class Item>
void graph<Item>::addVertex(const Item& label){
	/*Assume for now enough capcity. Not sure How I would transfer over an array of nodes.....list copy???? */
	//node<int> newVertex= new node<int>(numOfVertices);
	list[numOfVertices] = new node<int>(numOfVertices, NULL);
	cout << "Checking " << list[numOfVertices]->data() << endl;
	labels[numOfVertices] = label;
	++numOfVertices;
}

template<class Item>
void graph<Item>::addEdge(const size_t& source, const size_t& target, const size_t& weight){
	assert((numOfVertices>0) && ((source < numOfVertices) && (target < numOfVertices)));
	assert(!isConnected(source, target));/*Make sure these two verticies aren't already conencted.*/
	/*The data is a nodeeeeeeeeeeee*/
	list[source]->list_insert(list[source], list[target]);
}

template<class Item>
void graph<Item>::print(){
	for(size_t i = 0; i < numOfVertices; i++){
		cout << list[i]->data() << endl;
	}
}

template<class Item>
size_t graph<Item>::size() const {
	return numOfVertices;
}

template<class Item>
bool graph<Item>::isConnected(const size_t& source, const size_t& target){
	assert(numOfVertices> 0);
	assert(source < numOfVertices);
	assert(target < numOfVertices);
	/*Check if anything in that list links to the taarget link. to get target list[target]*/
	bool isFound = false;
	node<int> * current = list[source]; /*Set current to the node of the head at source*/
	while((current !=NULL) && (!isFound)){
		if(current->link() == list[target]){
			isFound = true;
		}
		current = current->link();
	}
	return isFound;
	
}



#endif
