#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__
#include "Sefa_B_HW6_Q1.h"
//#include "Sefa_B_HW5_Q5b.cpp"

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

/*NOTE this function only works for labels.*/
template<class Item>
void graph<Item>::resize(const size_t& new_size){
	if(new_size == CAPACITY)
		return; /*This is saying, if what we want is already the same, dont do anything.*/
	if(new_size < numOfVertices)
		return; /*This is saying that if we want something smaller than the entries, dont do it becuase we cant lose stuff.*/
	Item * newLabels = new Item[new_size];
	for(size_t i = 0; i < numOfVertices; i++){
		newLabels[i] = labels[i];
	}
	delete labels;
	CAPACITY = new_size;
	labels = newLabels;
}



#if 0 
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

#endif


template<class Item>
void graph<Item>::addVertex(const Item& label){
	if(!(numOfVertices < CAPACITY)){
		size_t size = CAPACITY*2;
	
		int ** larger = new int*[size];
		for(size_t i = 0; i < size; i++){
			larger[i] = new int[size];
		}
		for(size_t i = 0; i < numOfVertices; i++){
			for(size_t j = 0; j<numOfVertices; j++)
				larger[i][j] = edges[i][j];
		}
	
	
		for(size_t i = 0; i < numOfVertices; i++){
			delete [] edges[i];
		}
		delete edges;
	
		edges  = larger;

		int * largerLabels = new int[size];
		for(size_t i = 0; i < numOfVertices; i++){
			largerLabels[i] = labels[i];
		}
		delete labels;
		labels = largerLabels;
		CAPACITY = size;
	}
	labels[numOfVertices] = label;
	numOfVertices++;


#if 0
	/*If we don't have enough space, 
	 * we need to increase the capacity for everything*/
	size_t oldCap = CAPACITY;
	if(!(numOfVertices < oldCap)){
		/*Resize every column....possibly row...forgot but i think its column.*/
		int ** biggerEdges = new int*[oldCap*2];
		for(size_t i = 0; i < (oldCap*2); i++){
			biggerEdges[i] = new int[oldCap*2];
		}
		for(size_t i = 0; i < oldCap; i++){
			for(size_t j = 0; j < oldCap; j++){
				biggerEdges[i][j] = edges[i][j];
			}
		}
	
		/*Never set edges to bigger?????????????????????????*/
		for(size_t i = 0; i <oldCap*2; i++){
			delete [] edges[i];
			/*for(size_t j = 0; j < oldCap*2;j++){
				
			}*/
		}
		delete edges;
		
		edges = biggerEdges;
		/*for(size_t i = 0; i < oldCap*2; i++){
			edges[i]=biggerEdges[i];
		}*/
		/*for(size_t i = 0; i< CAPACITY; i++){
			
		}*/

		resize(oldCap);
		/*NOTE, now capacity doesn't need to be changed once more because now we need to make sure its the good way.*/
	}
	/*If everything is resized as needed, now just append everything to the end.*/
	labels[numOfVertices++] = label;
	cout << "VinAdd: " << numOfVertices << endl;
	/*Don't really have to do anything to the edges here because by default they are set to 0. If not, then wuld have to go through that row/column and set to 0.*/
	for(size_t i = 0; i < numOfVertices; i++){
		for(size_t j = 0; j < numOfVertices; j++){
			cout << edges[i][j] << "            ";
		}
		cout << endl;
	}
#endif
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
	edges[source][target] = 0;
}

template<class Item>
void graph<Item>::print(){
	//cout << "VinP " <<numOfVertices;
	for(size_t i = 0; i < numOfVertices; i++){
		
		//cout << labels[i] << endl;
		//cout << "?" << endl;
		for(size_t j = 0; j < numOfVertices; j++){
			cout << edges[i][j] << "\t";
			//cout << "NONO" << endl;
			//cout << "...i: " << i << " j: " << j << "      ";// <<endl;
		}
		//cout << "YIKES" << endl;
		cout << endl;
	}
	//cout << "HEREE" << endl;
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
	Item* neighBorWeights = new Item[numNeigh];
	size_t indexNeigh = 0;
	for(size_t i = 0; i < numOfVertices; i++){
		/*cout << "indexN   "   <<indexNeigh << endl;*/
		if(isConnected(vertex, i)){
			vertexNeighbors[indexNeigh] = i;/*edges[vertex][i]; */
			//++indexNeigh;
			neighBorWeights[indexNeigh] = edges[vertex][i]; /*store edge weights*/
			++indexNeigh;
		}
	}
/*
	for(size_t i = 0; i < numNeigh; i++){
				cout << "Vertex " << vertexNeighbors[i] << " edge " << neighBorWeights[i] << endl; 
					}
		
*/

	heapSort(vertexNeighbors, neighBorWeights, numNeigh);
	/*
	for(size_t i = 0; i < numNeigh; i++){
		cout << "Vertex " << vertexNeighbors[i] << " edge " << neighBorWeights[i] << endl; 
	}
	*/
	
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

template<class Item>
size_t graph<Item>::getWeight(const size_t& source, const size_t& target){
	assert(numOfVertices > 0);
	assert(source < numOfVertices && target<numOfVertices);
	return edges[source][target];
}
#if 0
/*NOTE not sure if I needed a process function for this function, such as print or something... If so, then I would need to add another data structure (array), that would keep track of the order in which vertices were traversed. */
template<class Item>
void graph<Item>::depthFirstSearch(graph<Item>& G, const Item& vertex){ /*NOTE may need to implement using pointers. */
	assert(vertex < G.size());
	bool * vertexPassed = new bool[G.size()];
	/*/int * neighbors = G.neighbors(vertex);*/
	/*cout << "This works" << endl;*/
	//vertexPassed = 
	iterateDFS(G, vertex, vertexPassed);
	/*cout << "Made it here " << endl;*/
}


/*Chaning to void because the return wont let it reprocess other nodes...wait this is still not going to solve the problem. Everytime a recurive problem is called, we never get to go on foward. I think the statement must be placed within a while loop.....but how.......*/
template<class Item>
void graph<Item>::iterateDFS(graph<Item>& G, const Item& vertex, bool* vertexPassed){//(int * neighbors, const Item& vertex, bool * vertexPassed){
	/*cout << "Here 1" << endl;*/
	cout << "Vertex Val " << vertex << endl;
	size_t numNeighbors = 0; /*NOTE must pass a size to get number of neighbors a vertex has. */
	
	int * vertexNeighbors = G.neighbors(vertex, numNeighbors);
	/*cout << "NUmNe " << numNeighbors << endl;*/
	bool unprocessedNeighbors = false;
	for(size_t i = 0; i < numNeighbors; i++){
		if(vertexPassed[vertexNeighbors[i]] == false)
			unprocessedNeighbors = true;
	}
	vertexPassed[vertex] = true;
	/*cout <<  << endl;*/
	if(numNeighbors == 0 || !unprocessedNeighbors){
		/*This is checking that we have no other vertex to traverse to*/
		vertexPassed[vertex] = true;
	/*	cout << "Here last " << endl; */
		return;// vertexPassed; 
	}
	/*NEED to sort the neightbors in order of increasing to decreasing...im going to use heapsort for HW5.*/
	//heapSort(vertexNeighbors ,numNeighbors);	
	/*for(size_t i = 0; i < numNeighbors; i++){
		cout << vertexNeighbors[i] << endl;
	}*/


	Item nextVertex = 0; /*Will hold the next vertex that we need to iterate through*/
	for(size_t i = 0; i < numNeighbors; i++){
		/*cout << "here i " << endl;*/
		/*Compare weights and make sure it hasnt been checked.*/
		/*cout << (G.getWeight(vertex, vertexNeighbors[i]) < G.getWeight(vertex, nextVertex)) << endl;*/
		//cout << 
		//if((G.getWeight(vertex, vertexNeighbors[i]) < G.getWeight(vertex, nextVertex)) && (vertexPassed[i] == false)){
			//nextVertex = i; /*Store the next vertex with the lowest weight. */
		//}
		if(vertexPassed[vertexNeighbors[i]] == false){
			iterateDFS(G, vertexNeighbors[i], vertexPassed);
		}
	}
	/*Once we get the next vertex, recall this function*/
	//return 
	//iterateDFS(G, vertexNeighbors[nextVertex], vertexPassed);
}


/*void sortArr(int * arr, size_t size){
	int* sorted = new int[size];
	for(){
	}


}*/

#endif

#if 0

/*NOTE NOTE NOTE NOTE NOTE This code is from HW5_Q5b.cpp*/



/*NOTE these aren't template functions because they actually dont have anything to do with the heap. It as if constructing the heap itself. It just configures the current array so that its as a heap. Doesn't use heapClass. */
void makeHeap(int arr[], size_t size){
	/*heap<int> * heapArr = new heap<int>(size);
	for(size_t i = 0; i < size; i++){
		heapArr->addNode(arr[i]);
	}*/

	/*NOTE this is literally like add. The way the book is doing it is that it is teating heapsort as its own thing. Meaning that it just changes the arary thats given instead of actually making a heap as an array.*/
	size_t indexNew;
	for(size_t i = 1; i < size; i++){
		indexNew = i;
		while((indexNew>0) && (arr[indexNew] > arr[(indexNew-1)/2])){
			int temp = arr[indexNew];
			arr[indexNew] = arr[(indexNew-1)/2];
			arr[(indexNew-1)/2] = temp;
			indexNew = (indexNew-1)/2;
		}
	}
}

/*This function is basically like delete, just moves larger child up, and root down.*/
void reheapify_down(int arr[], size_t size){
	size_t i = 0;
	if(size == 1){
		return;
	}
	/*While we are not a heap, and we have a child to swap with.*/
	while((i<size) && (2*i+1)<size){//&& ((2*i+1)<size && (2*i+2) < size)){
		/*Again like in delete, if */
		int temp = arr[i];
		if((2*i+2) >= size){ /*NOTE if our right side is too big, stop this loop.*/
			i = size;
		}
		else if((arr[i] < arr[2*i+1])&&(arr[(2*i+1)]>=arr[2*i+2])){
			arr[i] = arr[2*i+1];
			arr[2*i+1] = temp;
			i = 2*i+1;
		}
		else if((arr[i]< arr[2*i+2]) && (arr[2*i+2] > arr[2*i+1])){
			arr[i] = arr[2*i+2];
			arr[2*i+2] = temp;
			i = 2*i+2;
		}
		else{
			i = size;
		}
	}
				
}
							


void heapSort(int arr[], size_t size){
	size_t i;
	makeHeap(arr, size); /*Turn array into heap.*/
	/*for(size_t i = 0; i < size; i++){
		cout << arr[i] << endl;
	}*/
	i = size;
	while(i > 1){
		--i; /*Decrease index so its valid. Start from last.*/
		/*Swap root with last. */
		int temp = arr[0];
		arr[0] = arr[i]; 
		arr[i] = temp;
		reheapify_down(arr, i); 
		/*Make sure max is always at the top by rearragning.*/
	}

}

#endif





#endif
#if 0
/*NOTE NOTE NOTE NOTE NOTE This code is from HW5_Q5b.cpp*/



/*NOTE these aren't template functions because they actually dont have anything to do with the heap. It as if constructing the heap itself. It just configures the current array so that its as a heap. Doesn't use heapClass. */
void makeHeap(int arr[], size_t size){
	/*heap<int> * heapArr = new heap<int>(size);
	for(size_t i = 0; i < size; i++){
		heapArr->addNode(arr[i]);
	}*/

	/*NOTE this is literally like add. The way the book is doing it is that it is teating heapsort as its own thing. Meaning that it just changes the arary thats given instead of actually making a heap as an array.*/
	size_t indexNew;
	for(size_t i = 1; i < size; i++){
		indexNew = i;
		while((indexNew>0) && (arr[indexNew] > arr[(indexNew-1)/2])){
			int temp = arr[indexNew];
			arr[indexNew] = arr[(indexNew-1)/2];
			arr[(indexNew-1)/2] = temp;
			indexNew = (indexNew-1)/2;
		}
	}
}

/*This function is basically like delete, just moves larger child up, and root down.*/
void reheapify_down(int arr[], size_t size){
	size_t i = 0;
	if(size == 1){
		return;
	}
	/*While we are not a heap, and we have a child to swap with.*/
	while((i<size) && (2*i+1)<size){//&& ((2*i+1)<size && (2*i+2) < size)){
		/*Again like in delete, if */
		int temp = arr[i];
		if((2*i+2) >= size){ /*NOTE if our right side is too big, stop this loop.*/
			i = size;
		}
		else if((arr[i] < arr[2*i+1])&&(arr[(2*i+1)]>=arr[2*i+2])){
			arr[i] = arr[2*i+1];
			arr[2*i+1] = temp;
			i = 2*i+1;
		}
		else if((arr[i]< arr[2*i+2]) && (arr[2*i+2] > arr[2*i+1])){
			arr[i] = arr[2*i+2];
			arr[2*i+2] = temp;
			i = 2*i+2;
		}
		else{
			i = size;
		}
	}
				
}
							


void heapSort(int arr[], size_t size){
	size_t i;
	makeHeap(arr, size); /*Turn array into heap.*/
	/*for(size_t i = 0; i < size; i++){
		cout << arr[i] << endl;
	}*/
	i = size;
	while(i > 1){
		--i; /*Decrease index so its valid. Start from last.*/
		/*Swap root with last. */
		int temp = arr[0];
		arr[0] = arr[i]; 
		arr[i] = temp;
		reheapify_down(arr, i); 
		/*Make sure max is always at the top by rearragning.*/
	}

}

#endif

