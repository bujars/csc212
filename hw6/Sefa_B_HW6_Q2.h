#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <cstdlib>
#include <cassert>
#include <iostream>
//#include <list>

#include <string> /*"to hold the double data type ie vertex,weight" */

//#include "Sefa_B_HW3.h"
#include "node2.h" /*NOTE, this was taken from the textbook. */
using namespace std;

template<class Item>
class graph{
	public:
		graph(const size_t init_cap= 5); /*init cap is to set the size of the array of head_pointers or the vertices*/
		~graph();
		graph(const graph<Item>& source);
		void operator=(const graph<Item>& source);
		/*This will set a node at list[numOfVertices]*/
		void addVertex(const Item& label);
		/*This will just insert into list[source] -> target*/
		void addEdge(const size_t& source, const size_t& target, const size_t& weight);
		/*This will just call list remove at list[source]->target*/
		void removeEdge(const size_t& source, const size_t& target);
		/*This just returns numOfVertices*/
		size_t size() const;
		/* This will go through list[i] and do listLengh for each. */
		size_t numEdgesTotal();
		/*This will just go through the list and calculate the length.*/
		size_t numEdges(const size_t& source, const size_t& target);
		/*Not sure if I need this function, but basically list[source]->search(target) != NULL. On second thought yes need, because search for such a pointer, if found, then you can just increase data...*/
		bool isConnected(const size_t& source, const size_t& target);
		/*Just for my testing purposes of checking head_ptr; */
		void print();
		/*Gets the vertex value from the string inside node "vertex.weight"*/
		size_t getVertexNum(node<string> * current);
		size_t getWeightNum(node<string> * current);
	private:
		//node<int> * list; /*I will go with this method, where nodes are ints because of vertex number. THis is an array of the head pointers*/
		Item * labels; /*This is just an array that holds the labels of each item .*/
		node<string> ** list;//*/ /*Array of Nodes? I could be mistaken but array of nodes is just node* list. This creates an array and each point is then anode. aAt each index you can just use node operations... What I have below i think is a linked list of a linked list...?*/
		/*I think using Item here may allow us to use it in terps of if two labels are attached to one another??? 
		 * Like in Q1 we had labels sepaerate from edge connections....Not sure actually will hve to get back to.*/
		size_t numOfVertices;
		size_t CAPACITY;
};
#include "Sefa_B_HW6_Q2.cpp"
#endif
