#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <cstdlib>
#include <cassert>
#include <iostream>
//#include "../hw5/Sefa_B_HW5_Q5b.cpp"


using namespace std;

template<class Item>
class graph{
	public:
		graph(const size_t& init_cap = 1);
		graph(const graph<Item>& source);
		~graph();
		void operator=(const graph<Item>& souce);
		/*NOTE this resize function currently only works for labels and each column, but not row for edges. Thus I will manually resize the 2D array in addVertex.*/
		/*void resize(Item* arr, const size_t& new_size);*/
		void resize(const size_t& new_size);
		/*Adding each vertex where a vertex has a label('it's data')*/
		void addVertex(const Item& label);
		/*Adding an edge is basically just connecting to vertecies, so need the values for that.*/
		void addEdge(const size_t& source, const size_t& target, const size_t& weight);
		void removeEdge(const size_t& source, const size_t& target);
		void print();
		size_t size() const; /*Returns the number of vertices*/
		size_t numEdgesTotal(); //const; /*NOTE not sure if this wants total number of edges, or if it wants specific edges at a vale, and thus would need to have a source to target value. THUS I am spliting it between two ways*/
		size_t numEdges(const size_t& vertex);
		bool isConnected(const size_t& source, const size_t& target); /*NOTE this can just call numEdges and compare it to 0. */
		Item* neighbors(const size_t& vertex, size_t& size); /*Returns an 'array' of the vertices that are connected to the given vertex.*/
		size_t getWeight(const size_t& source, const size_t& target);

		/* NOTE not sure if I needed a process function for this function, 
		 * such as print or something... If so, then I would need to add another 
		 * data structure (array), that would keep track of the order 
		 * in which vertices were traversed. */
		void depthFirstSearch(graph<Item>& G, const Item& vertex); 
		/*NOTE may need to implement using pointers. */

		//bool * 
		void iterateDFS(graph<Item>& G, const Item& vertex, bool* vertexPassed);
	
	
	private:
		int ** edges; /*THe "weighted" edges array*/
		size_t CAPACITY; 
		size_t numOfVertices; /*Basically like a count*/
		Item * labels; /*Data of each vertex*/


};

//#include "Sefa_B_HW6_Q1.cpp"


void makeHeap(int arr[], size_t size);
void reheapify_down(int arr[], size_t size);
void heapSort(int arr[], size_t size);
//#include "Sefa_B_HW5_Q5b.cpp"

#include "Sefa_B_HW6_Q1.cpp"

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


//#include "Sefa_B_HW6_Q1.cpp"
#endif

