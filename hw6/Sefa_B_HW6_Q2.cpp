#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__
#include "Sefa_B_HW6_Q2.h"

template<class Item>
graph<Item>::graph(const size_t init_cap){
	CAPACITY = init_cap;
	labels = new Item[CAPACITY];
	for(size_t i = 0; i < CAPACITY; i++){
		labels[i] = Item();
	}
	//list = new node<int>(CAPACITY);
	
	/* "A dynamic 2D array is basically an arry of pointers to arrays" 
	 * So, first declare an array of the type that it will be pointing too with capacity.
	 * then declare each pointer in the array to whatever it need be, here its nodes. */
	
	list = new node<string>*[CAPACITY];
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
graph<Item>::graph(const graph<Item>& source){
	CAPACITY = source.CAPACITY;
	list = new node<string>*[CAPACITY];
	labels = new Item[CAPACITY];
	numOfVertices = source.numOfVertices; 
	for(size_t i = 0; i < CAPACITY; i++){
		labels[i] = source.labels[i];
		node<string> * head;
		node<string> * tail;
		list_copy(source.list[i],head,tail);
		list[i] = head;
	}
}


template<class Item>
void graph<Item>::operator=(const graph<Item>& source){
	if(this == &source){
		return;
	}
	/*CAPACITY = source.CAPACITY;*/
	for(size_t i =0; i< CAPACITY; i++){
		list_clear(list[i]);
	}
	CAPACITY = source.CAPACITY;
	delete labels;
	list = new node<string>*[CAPACITY];
	labels = new Item[CAPACITY];
	for(size_t i = 0; i < CAPACITY; i++){
		labels[i] = Item();
	}
	numOfVertices = source.numOfVertices; 
	for(size_t i = 0; i < CAPACITY; i++){
		labels[i] = source.labels[i];
		node<string> * head;
		node<string> * tail;
		list_copy(source.list[i],head,tail);
		list[i] = head;
	}
	/*numOfVertices = source.numOfVertices; */
}

template<class Item>
void graph<Item>::addVertex(const Item& label){
	/*Assume for now enough capcity. Not sure How I would transfer over an array of nodes.....list copy???? */
	//node<int> newVertex= new node<int>(numOfVertices);
	//int data[2] = {numOfVertices, 0}; /*All head pointer data is going to be first what the vertex val is, and 0 to now weight*/
	if(!(numOfVertices < CAPACITY)){
		size_t size = CAPACITY*2;
		Item * labelsNew = new Item[size];
		for(size_t i = 0; i < size; i++){
			labelsNew[i] = Item();
		}
		for(size_t i = 0; i < numOfVertices; i++){
			labelsNew[i] = labels[i];
		}
		delete labels;
		labels = labelsNew;
		node<string>** listNew = new node<string>*[size];
		for(size_t i = 0; i < numOfVertices; i++){
			node<string> * head;
			node<string> * tail;
			list_copy(list[i], head, tail);
			listNew[i] = head;
		}
		for(size_t i = 0; i < numOfVertices; i++){
			list_clear(list[i]);
		}
		delete [] list;
		list = new node<string>*[size];
		for(size_t i = 0; i < size; i++){
			node<string> * head;
			node<string> * tail;
			list_copy(listNew[i], head, tail);
			list[i] = head;
		}
		CAPACITY = size;
	}
	string data = "" + to_string(numOfVertices) + "." + to_string(0);
	list[numOfVertices] = new node<string>(data, NULL);
	/*cout << "Checking " << list[numOfVertices]->data() << endl;*/
	labels[numOfVertices] = label;
	++numOfVertices;
}

template<class Item>
void graph<Item>::addEdge(const size_t& source, const size_t& target, const size_t& weight){
	assert((numOfVertices>0) && ((source < numOfVertices) && (target < numOfVertices)));
	assert(!isConnected(source, target));/*Make sure these two verticies aren't already conencted.*/
	string data = "" + to_string(target)+"." + to_string(weight); /*NOTE the target and weight is sotred in a string. Target first then weight*/
	/*The data is a nodeeeeeeeeeeee*/
	/*list[source]->*/ /*list[source] used as head pointer handles where  new node is supposed to be added. its a void function.*/
	list_insert(list[source], data); /*insert after the head pointer the data. */
}

template<class Item>
void graph<Item>::removeEdge(const size_t& source, const size_t& target){
	assert((numOfVertices>0) && ((source < numOfVertices) && (target < numOfVertices)));
	assert(isConnected(source, target));/*Make sure the two edges are actually connected.*/

	/*Have to find the node previous to the one im looking for to use list_remove.*/
	node<string> * nodeRemove = list[source];// = list_locate(list[source], )
	node<string> * prevNode = NULL; /*lets set to current*/
	bool found = false;
	size_t valCurr = getVertexNum(nodeRemove); 
	while(nodeRemove!=NULL && !found){
		if(valCurr == target){
			found = true;
		}
		else{
			prevNode = nodeRemove;
			nodeRemove = nodeRemove->link();
			if(nodeRemove!=NULL) /*NOTE NOTE NOTE. This must be checked because our checking if at end is very poor. so precaution not to call function*/
				valCurr = getVertexNum(nodeRemove);
		}
	}
	cout << prevNode->data() << endl;
	
	/*Now that we have previous ptr, remove it.*/
	//remove_ptr = previous_ptr->link( );
	prevNode->set_link(nodeRemove->link( ));
	

	//list_remove(prevNode);
}



template<class Item>
void graph<Item>::print(){
	for(size_t i = 0; i < numOfVertices; i++){
		node<string> * current = list[i];
		cout << "Vertex " << getVertexNum(current) << "   Edges ";
		current = current->link();
		while(current!=NULL){
			cout << getVertexNum(current) << " ";
			current = current->link();
			/*if(current!=NULL) *//*NOTE NOTE NOTE. This must be checked because our checking if at end is very poor. so precaution not to call function*/
				/*currentVal = getVertexNum(current);*/
		}
		cout << endl;
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
	node<string> * current = list[source]; /*Set current to the node of the head at source*/
	size_t currentVal = getVertexNum(current);/*stoi((current->data()).substr(0, (current->data()).find(".")));*/
	/*cout << currentVal << endl;
	cout << getWeightNum(current) << endl;*/
	while((current !=NULL) && (!isFound)){		
		if(currentVal == target)
			isFound = true;
		/*if(current->link() == list[target]){
			isFound = true;
		}*/
		current = current->link();
		if(current!=NULL) /*NOTE NOTE NOTE. This must be checked because our checking if at end is very poor. so precaution not to call function*/
			currentVal = getVertexNum(current);
	}
	return isFound;
	
}

template<class Item>
size_t graph<Item>::getVertexNum(node<string> * current){
	assert(current!=NULL);
	return stoi((current->data()).substr(0, (current->data()).find(".")));
}

template<class Item>
size_t graph<Item>::getWeightNum(node<string> * current){
	assert(current!=NULL);
	return stoi((current->data()).substr((current->data()).find(".")+1));
}

template<class Item>
int * graph<Item>::neighbors(const size_t& source, size_t& size){
	assert(source < numOfVertices); /*Make sure we have in list. */
	size_t length = list_length(list[source]);/*Get the space we need*/
	cout << "LEN "<<length << endl;	
	int * neighborHood = new int[length-1]; /*Notice -1 because dont want to include head pointer. */
	size_t index = 0;

	node<string> * current = list[source];
	current = current->link(); /*move to first thing*/
	//for(size_t i = 1; i < length; i++){ /*Go through the neghbors now...*/
	while(current!=NULL){
		neighborHood[index] = getVertexNum(current);
		index++;
		current = current->link();
	}
	size = length-1;
	//cout << "SIZE " << end
	return neighborHood;
}

template<class Item>
size_t graph<Item>::numEdges(const size_t& vertex){
	assert((numOfVertices > 0)&& (vertex < numOfVertices));
	size_t totEdge = list_length(list[vertex])-1;
	return totEdge;
}

template<class Item>
size_t graph<Item>::numEdgesTotal(){
	assert(numOfVertices > 0);
	size_t totEdges = 0;
	for(size_t i = 0; i < numOfVertices; i++){
		totEdges+= (list_length(list[i])-1);
	}
	return totEdges;
}




#endif
