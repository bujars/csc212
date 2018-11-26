
#include "Sefa_B_HW6_Q1.h"
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
	g->removeEdge(2,0);
	/*g->removeEdge(2,0);*//*isConnected works and so does remove.*/
	g->print();
	return 0;
}

