#if 0
/*NOTE I include Q1 for this assignment. Q2 can also work.*/
#include "Sefa_B_HW6_Q1.h"

/*NOTE not sure if I needed a process function for this function, such as print or something... If so, then I would need to add another data structure (array), that would keep track of the order in which vertices were traversed. */
template<class Item>
void depthFirstSearch(const graph<Item>& G, const Item& vertex); /*NOTE may need to implement using pointers. */

template<class Item>
bool * iterateDFS(const graph<Item>& G, const Item& vertex, bool* vertexPassed);//(int * neighbors, const Item& vertex, bool * vertexPassed){


//#include "Sefa_B_HW6_Q3.cpp"

#endif

#include "Sefa_B_HW6_Q1.h"
	/* NOTE not sure if I needed a process function for this function, 
		 * 		 * such as print or something... If so, then I would need to add another 
		 * 		 		 * data structure (array), that would keep track of the order 
		 * 		 		 		 * in which vertices were traversed. */
	template<class Item>
	void depthFirst(graph<Item>& G, const size_t& vertex); 
	/*NOTE may need to implement using pointers. */
	
	template<class Item>
	void breadthFirst(graph<Item>& G, const size_t& vertex);

	/*bool * */
	template<class Item>
	void iterateDF(graph<Item>& G, const size_t& vertex, bool* vertexPassed);

#include "Sefa_B_HW6_Q3.cpp"

