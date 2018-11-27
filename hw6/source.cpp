#include "Sefa_B_HW6_Q2.h"
#include "node2.h"
int main(){
	graph<int> d;//(30);// = new graph<int>(30);
	//d.addVertex(2);
	//d.print();
	
	node<int> ** list;
	//list->list_head_insert(0);
		
	return 0;
}




#if 0
#include "Sefa_B_HW6_Q1.h"
#include "Sefa_B_HW3.h"
int main(){
	graph<int> * g = new graph<int>(50);
	graph<int> *s = new graph<int>(*g);
	g->addVertex(0); /*Set vertex 0*/
	g->addVertex(1); 
	g->addVertex(2);
	g->addVertex(3);
	g->addVertex(4);
	g->addVertex(5);
	g->addEdge(0, 1);
	g->addEdge(2,0);
	g->addEdge(0,1);
	g->addEdge(0,3);
	g->addEdge(0,5);
	//g->removeEdge(2,0);
	/*g->removeEdge(2,0);*//*isConnected works and so does remove.*/
	//g->print();
	cout << g->numEdges(0,1) << endl;
	cout << g->numEdgesTotal() << endl;
	cout << g->size() << endl;
	cout << "isC"<< g->isConnected(0,1) << endl;
	size_t size = 0;
	int * neigh = g->neighbors(0, size);
	cout << endl;
	for(size_t i = 0; i < size; i++){
		cout << neigh[i] << " "; 
	}
	cout << endl << endl;
	cout << endl << endl;
	g->print();


	node * h;

	return 0;
}

#endif
