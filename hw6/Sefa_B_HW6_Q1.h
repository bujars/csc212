#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <cstdlib>
#include <cassert>
#include <iostream>

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
	private:
		int ** edges; /*THe "weighted" edges array*/
		size_t CAPACITY; 
		size_t numOfVertices; /*Basically like a count*/
		Item * labels; /*Data of each vertex*/


};
#include "Sefa_B_HW6_Q1.cpp"
#endif

