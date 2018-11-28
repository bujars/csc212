#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__
#include "Sefa_B_HW6_Q1.h"

/*NOTE weight cannot be - or 0. */



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
		int ** biggerEdges = new int*[oldCap*2];
		for(size_t i = 0; i < oldCap*2; i++){
			biggerEdges[i] = new int[oldCap*2];
		}
		for(size_t i = 0; i < numOfVertices; i++){
			for(size_t j = 0; j < numOfVertices; j++){
				biggerEdges[i][j] = edges[i][j];
			}
		}
		resize(labels, oldCap);
		/*NOTE, now capacity doesn't need to be changed once more because now we need to make sure its the good way.*/
	}
	/*If everything is resized as needed, now just append everything to the end.*/
	labels[numOfVertices++] = label;
	/*Don't really have to do anything to the edges here because by default they are set to 0. If not, then wuld have to go through that row/column and set to 0.*/
}

template<class Item>
void graph<Item>::addEdge(const size_t& source, const size_t& target, const size_t& weight){
	assert((numOfVertices > 0) && ((source < numOfVertices) && (target < numOfVertices)));
	assert(!isConnected(source,target));
	assert(weight > 0);
	/*cout << "WTF " << endl;*/
	edges[source][target] = weight;
}

template<class Item>
size_t graph<Item>::numEdges(const size_t& vertex){
	assert((numOfVertices > 0) && ((vertex < numOfVertices)));
	size_t totEdge = 0;
	for(size_t i = 0; i < numOfVertices; i++){
		if(isConnected(vertex, i)){
			totEdge++;
		}
	}
	return totEdge;
}

template<class Item>
bool graph<Item>::isConnected(const size_t& source, const size_t& target){
	assert((numOfVertices > 0) && ((source < numOfVertices) && (target < numOfVertices)));
	/*cout << "NUME     "<<numEdges(source, target) << endl;*/
	return (edges[source][target] != 0);
}

template<class Item>
void graph<Item>::removeEdge(const size_t& source, const size_t& target){
	assert((numOfVertices > 0) && ((source < numOfVertices) && (target < numOfVertices)));
	assert(isConnected(source, target));
	edges[source][target]--;
}

template<class Item>
void graph<Item>::print(){
	for(size_t i = 0; i < numOfVertices; i++){
		/*cout << labels[i] << endl;*/
		for(size_t j = 0; j < numOfVertices; j++){
			cout << edges[i][j] << "\t";
		}
		cout << endl;
	}
}

/*Pre-condition, must give a size and a vertex looking for. Size will be adjusted.*/
template<class Item>
Item* graph<Item>::neighbors(const size_t& vertex, size_t& size){
	assert((vertex < numOfVertices) && (numOfVertices > 0));
	/*Item * vertexNeighbors = new*/ 
	/*Go through the row and count the number of vertices has neighrbor with to get size to set array. */
	size_t numNeigh = numEdges(vertex);/*0;*/
	/*cout << "NUM V " << numOfVertices << endl;*/
#if 0
	for(size_t i = 0; i < numOfVertices; i++){
		/*cout << edges[vertex][i] << endl;
		cout << "CONNECTED " <<isConnected(0, edges[0][i]) << endl;*/
		if(isConnected(vertex, i)){
			/*cout << edges[vertex][i] <<  " " << i << endl;*/
			++numNeigh;
		}
	}
#endif
	/*cout << "numN  " << numNeigh << endl;*/
	Item* vertexNeighbors = new Item[numNeigh];
	size_t indexNeigh = 0;
	for(size_t i = 0; i < numOfVertices; i++){
		/*cout << "indexN   "   <<indexNeigh << endl;*/
		if(isConnected(vertex, i)){
			vertexNeighbors[indexNeigh] = i;/*edges[vertex][i]; */
			++indexNeigh;
		
		}
	}
	size = numNeigh;
	return vertexNeighbors;
}

template<class Item>
size_t graph<Item>::numEdgesTotal(){ //const{
	assert(numOfVertices>0);
	size_t totEdges = 0;
	for(size_t i = 0; i < numOfVertices; i++){
		for(size_t j = 0; j < numOfVertices; j++){
			//if(this->isConnected(i, j)){
				totEdges++;/*= totEdges + numEdges(i,j);*/ /*This was before I knew they all have 1 edge.*/
			//}
		}
	}
	return totEdges;
}

template<class Item>
size_t graph<Item>::size() const{
	return numOfVertices;
}

#endif

