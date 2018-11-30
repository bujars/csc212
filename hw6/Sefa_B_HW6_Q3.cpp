#include "Sefa_B_HW6_Q1.h"


/*NOTE not sure if I needed a process function for this function, such as print or something... If so, then I would need to add another data structure (array), that would keep track of the order in which vertices were traversed. */
template<class Item>
void depthFirstSearch(graph<Item>& G, const size_t& vertex){ /*NOTE may need to implement using pointers. */
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
void iterateDFS(graph<Item>& G, const size_t& vertex, bool* vertexPassed){//(int * neighbors, const Item& vertex, bool * vertexPassed){
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



#if 0
#include "Sefa_B_HW6_Q3.h"

/*NOTE not sure if I needed a process function for this function, such as print or something... If so, then I would need to add another data structure (array), that would keep track of the order in which vertices were traversed. */
template<class Item>
void depthFirstSearch(const graph<Item>& G, const Item& vertex){ /*NOTE may need to implement using pointers. */
	assert(vertex < G.size());
	bool * vertexPassed = new bool[G.size()];
	//int * neighbors = G.neighbors(vertex);
	vertexPassed = iterateDFS(G, vertex, vertexPassed);
}

template<class Item>
bool * iterateDFS(const graph<Item>& G, const Item& vertex, bool* vertexPassed){//(int * neighbors, const Item& vertex, bool * vertexPassed){
	size_t numNeighbors = 0; /*NOTE must pass a size to get number of neighbors a vertex has. */
	int * vertexNeighbors = G.neighbors(vertex, numNeighbors);
	vertexPassed[vertex] = true;
	if(numNeighbors == 0){
		/*This is checking that we have no other vertex to traverse to*/
		vertexPassed[vertex] = true;
		return vertexPassed; 
	}
	Item nextVertex = 0; /*Will hold the next vertex that we need to iterate through*/
	for(size_t i = 0; i < numNeighbors; i++){
		/*Compare weights and make sure it hasnt been checked.*/
		if((G.getWeight(vertex, vertexNeighbors[i]) < G.getWeight(vertex, nextVertex)) && (vertexPassed[i] == false)){
			nextVertex = i; /*Store the next vertex with the lowest weight. */
		}
	}
	/*Once we get the next vertex, recall this function*/
	return iterateDFS(G, nextVertex, vertexPassed);
}

#endif
