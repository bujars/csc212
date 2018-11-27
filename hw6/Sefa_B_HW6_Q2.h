#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <list>
#include "Sefa_B_HW3.h"

using namespace std;

template<class Item>
class graph{
	public:
		graph(const size_t init_cap= 5); /*init cap is to set the size of the array of head_pointers or the vertices*/
		~graph();
		graph(const graph<Item>& source);

	private:
		node ** list; /*Array of Nodes?*/
		size_t numOfVertices;
};
#include "Sefa_B_HW6_Q2.h"
#endif
