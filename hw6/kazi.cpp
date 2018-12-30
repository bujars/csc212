#include "Sefa_B_HW6_Q1.h"


/*Note here you must pass a specific vertex. If none is passed, than we can just assume that vertex position (0,0) is the start*/

template<class Item>
bool cycleDepthFirst(graph<Item>& G, const size_t& vertex){ /*NOTE may need to implement using pointers. */
	assert(vertex < G.size());
	bool * vertexPassed = new bool[G.size()];
	for(size_t i = 0; i < G.size(); i++){
		vertexPassed[i] = false;
	}
	bool ret = iterateDF(G, vertex, vertexPassed);
	return ret;
}

/*A graph is said to have a cycle if there exist any back edge or self loop. Back edge means that if we go from a to b and there exist an edge from b to a, then return.*/


template<class Item>
bool iterateDF(graph<Item>& G, const size_t& vertex, bool* vertexPassed){
	size_t numNeighbors = 0; /*NOTE must pass a size to get number of neighbors a vertex has. */
	int * vertexNeighbors = G.neighbors(vertex, numNeighbors);
	bool unprocessedNeighbors = false;
	for(size_t i = 0; i < numNeighbors; i++){
		if(vertexPassed[vertexNeighbors[i]] == false)
			unprocessedNeighbors = true;
	}
	vertexPassed[vertex] = true;
	/* //NOTE dont think i can use this to simplify the process...But might need to get back to because not sure how its gonna effect everything below.
	if(numNeighbors == 0 || !unprocessedNeighbors){
		return;// vertexPassed; 
	}
	*/
	//Item nextVertex = 0; /*Will hold the next vertex that we need to iterate through*/
	bool returnVal = false; /*This will be the invariant of the methods and will hold how we are connected.*/
	for(size_t i = 0; i < numNeighbors; i++){
		if(vertexPassed[vertexNeighbors[i]] == false){
			bool loop = iterateDF(G, vertexNeighbors[i], vertexPassed);
			returnVal = loop;
			if(G.isConnected(vertexNeighbors[i], i) || loop){ /*Check if we have a back edge, or if we allready found one while recursivley iterateing, keep returning true to terminate function.*/
				return true;
			}

		}
	}
	return returnVal;

}

