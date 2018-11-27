#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <list>
//#include "Sefa_B_HW3.h"
#include "node2.h"
using namespace std;

template<class Item>
class graph{
	public:
		graph(const size_t init_cap= 5); /*init cap is to set the size of the array of head_pointers or the vertices*/
		~graph();
		graph(const graph<Item>& source);
		void operator=(const graph<Item>& source);
		void addVertex(const Item& label);
		void print();
	private:
		//node<int> * list; /*I will go with this method, where nodes are ints because of vertex number. THis is an array of the head pointers*/
		Item * labels; /*This is just an array that holds the labels of each item .*/
		node<Item> * list;//*/ /*Array of Nodes? I could be mistaken but array of nodes is just node* list. This creates an array and each point is then anode. aAt each index you can just use node operations... What I have below i think is a linked list of a linked list...?*/
		/*I think using Item here may allow us to use it in terps of if two labels are attached to one another??? 
		 * Like in Q1 we had labels sepaerate from edge connections....Not sure actually will hve to get back to.*/
		size_t numOfVertices;
		size_t CAPACITY;
};
#include "Sefa_B_HW6_Q2.cpp"
#endif
