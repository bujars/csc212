#include "Sefa_B_HW6_Q1.h"

#include <queue> /*This is to include priority queue*/
#include <functional> /*This is to include greater<int> which will be used to store the queue as a min queue*/
#include <limits.h>
template<class Item>
void dijkstra(graph<Item> g, const Item& startVertex){
	
	int distance[g.size()]; /*Will keep the minumum total distance to this vertex from start*/
	bool marked[g.size()]; /*Will keep track of which vertices we have already processed.*/
	int path[g.size()]; /*Will keep the value of the 'last'/smallest vertex that led to that path. */
	initializeSingleSource(g, startVertex, distance, marked, path); /*Sets all arrays to default values*/

	/* I am stuck in determining on how to go through the rest of the nodes, like do i call neighbors? but what if those neighbors end? how do i then go through the next set of neighbors?
	 *
	 * 
	 * the way geeks for geeks does it is they have two loops, one that goes through all the vertices, and then one that goes through the neighbors, and basically 'resets that value'. Ofc if we get to a vertex and it isnt conencted to anything, then nothing happens to it distance wise ofc.
	 * */
	
	/*go through all of our vertices*/
	for(size_t i = 0; i < g.size(); i++){
		int index = indexNextMin(g, distance, marked); /*So we should initally start off with  index = start */ /*Note, we don't necessarly need to check if its a neghbor because if it wasn't then it would have a value............ right? LOL...need to think this one through tooo....I think I would need a check that it isn't returned as infinity, because if it is, then thats it we are dont ebcause it means that nothing actually connected to this....unless it had infinity lenght..... I'm guessing assuming that isn't the case???? Something need to get back to...*/
		marked[i] = true; /*State that we have now gotten through this vertex*/
		if(distance[index] != INT_MAX){
			/*This if statement is basically to check if we are at a value where nothing has conencted to it, assuming that no paths can have max weight*/
			size_t numNeighbors = 0;
			int * neighborsIndex = neighbors(g, index, numNeighbors);
			for(size_t j = 0; j < numNeighbors; j++){
				if(marked[neighborsIndex[i]] == false){ /*Make sure that we haven't completely processed this vertex, otherwise we will be going thorugh it again...*/
					relax(g, index, neighborsIndex[i], distance, path); /*Go through the neighbors and adjust their distances if necessary. */
				}
			}
		}

	}

	/*Okay, instead of market, I think the point of the queue is to say, whichever verticies are on this queue we can still visit. Otherwise, we cannot visit it...But the thing that confuses me is how to retrieve the min/order the min in terms of weight. --> I know my neghbors function organizes them by weight, but priority queue wont be 'that smart' to do it*/ /* ==> need to figure this out because it will save a lot of work in organizing and looping through...but for now its whatever...*/
}

template<class Item>
void relax(graph<int> g, const size_t& indexSource, const size_t& indexTarget, int distance[], int path[]){
	int weightSourceTarget  = g.getWeight(indexSource, indexTarget) + distance[indexSource];
	if(distance[indexTarget] > (weightSourceTarget)){
		distance[indexTarget] = weightSourceTarget;
		path[indexTarget] = indexSource; /*Keep track of which index got us there.....*/ 
	}
}



/*NOTE ==> not really thinking this one out through beforehand, but do I need this for any vertex, or the adhaceny vertecies.....I think its for adjaceny, and then I need to pass the adjaceny array, and the size of that. Then using that, I */
template<class Item>
int indexNextMin(graph<Item> g, int distance[], bool marked[]){
	int smallestDistance = INT_MAX; /*NOT sure if we need to return this, but it can alwyas be retrieved as long as we have the distnace*/
	int index = -1;
	for(size_t i = 0; i < g.size(); i++){
		if(distance[i] <= smallestDistance && marked[i] == false){ /*NOTE might need to change but I have set to equal too...Incase we get two weights of equal len, want to consider both. */
			smallestDistance = distance[i];
			index = i;
		}
	}
	return index;

}



/*Function to initialize all initial values*/
template<class Item>
void initializeSingleSource(graph<Item> g, const Item& startVertex, int distance[], bool marked[], int path[]){
	for(size_t i = 0; i < g.size(); i++){
		distance[i] = INT_MAX;
		marked[i] = false;
		path[i] = -1; /*NOTE inital value is -1 meaning there is no vertex to actually get there.*/
	}
	distance[startVertex] = 0;
	/*marked[startVertex] = true;*/ /*Don't set this here, else then we cant find the neighbors. */
	path[startVertex] = 0; /*because only 0 can actually get there.*/
}






/* NOTE the way I originally was going to do it was have three arrays (which is really bad for storage), 
 * but one would be "marked" to tell us which vertiices we have already visited,
 * the second would be of the distances, and the third would hold "the path" or the vertex that last got it to that value 
 * (that way we could work our way backwards and see how to get to that position). 
 * (In a sense only needs two arrays), this is not including the array of the neighbors 
 * that we need to recaulatate through the loop. 
 *
 * The other thing was that this was going to have the "relax"/"build" included -> but this could always keep it outside.
 *
 * The way I am now going to implment it is the way the slides does using priority quueue.
 * The trouble I am having with priority queue is how to organize the vaues. Like its supposed to be by min weight, 
 * but how d we hold the edge value that corresponds with it. 
 * With linear array search, the way i was originaly going to do it, the index would be the posiiton of the vertex. This gets lost using a priority queue. 
 *
 * I lied, I am going to do it my way, but I will include the relax, build methods in mine. 
 * */
