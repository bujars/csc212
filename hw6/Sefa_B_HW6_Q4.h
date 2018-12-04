/*NOTE include queue. Use a priority queue to hold all of the verticies . Remove each smallst one as you go through the list. Use greater<int> as one of the parameters to reverse the order so that its a min heap. That way everytime you pop/front you will get the min val as one of the parameters to reverse the order so that its a min heap. That way everytime you pop/front you will get the min val.*/

/*NOTE never used priority queue or funcitonal...*/

#include "Sefa_B_HW6_Q1.h"
#include <queue> /*This is to include priority queue*/
#include <functional> /*This is to include greater<int> which will be used to store the queue as a min queue*/
#include <limits.h>

template<class Item>
void dijkstra(graph<Item> G, const Item& startVertex);
	//priority_queue<int> vertices(greater<int>);

template<class Item>
void relax(graph<int> g, const size_t& indexSource, const size_t& indexTarget, int 
distance[], int path[]);

template<class Item>
int indexNextMin(graph<Item> g, int distance[], bool marked[]);

template<class Item>
void initializeSingleSource(graph<Item> g, int distance[], bool marked[], int path[]);

#include "Sefa_B_HW6_Q4.cpp"
