#include "Sefa_B_HW6_Q1.h"
#include <queue> /* This is for BFS. Including the c++ one incase mine had any errors. */

/*NOTE not sure if I needed a process function for this function, such as print or something... If so, then I would need to add another data structure (array), that would keep track of the order in which vertices were traversed. */
template<class Item>
void depthFirst(graph<Item>& G, const size_t& vertex){ /*NOTE may need to implement using pointers. */
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
void iterateDF(graph<Item>& G, const size_t& vertex, bool* vertexPassed){//(int * neighbors, const Item& vertex, bool * vertexPassed){
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

template<class Item>
void breadthFirst(graph<Item>& G, const size_t& vertex){
	/*NOTE must search by weight. BFS works different from DFS in the sense that it vistis all its neighbors first, 
	 * before visiting more depth (versus DFS which tries to visit the longest path and then work its way back. )*/
	assert(vertex < G.size());/*First check that we have a valid vertex. */
	queue<Item> gQueue;
	gQueue.push(vertex); /*Push the first vertex that we will be looking at.*/
	/*The queue will help us by keeping track of which neighbors we need to visit next. */
	bool * vertexPassed = new bool[G.size()]; /* This will keep track of every vertex we need to pass.*/
	size_t numNeighbors = 0;
	Item * vertexNeighbors;/* = G.neighbors(vertex, numNeighbors); */
	/*NOTE! neighbors handles the sorting by weight thanks to my use of heapsort*/
	Item currentV;
	/*As long as we still have more neighbors to visit, */
	while(!gQueue.empty()){
		currentV = gQueue.front(); /*store the first guy.*/
		cout << currentV << endl; /*Print the order in which we visit the nodes.*/
		gQueue.pop();
		vertexPassed[currentV] = true; /*Mark the fact that we traverse the current vertex. */
		/*Find the neightbors*/
		vertexNeighbors = G.neighbors(currentV, numNeighbors);
		for(size_t i = 0; i < numNeighbors; i++){
			/*If we didnt pass that neighbor, then push it onto the queue to be visited. */
			if(vertexPassed[vertexNeighbors[i]] == false){
				vertexPassed[vertexNeighbors[i]] = true; /*Mark that you ment through this neightbor, otherwise its going to double go through them*/
				gQueue.push(vertexNeighbors[i]);
			}
		}
	}

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
