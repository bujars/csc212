#if 0
#include "Sefa_B_HW6_Q2.h"
#include "node2.h"
int main(){
	graph<int> d;//(30);// = new graph<int>(30);
	d.addVertex(2);
	d.print();
	cout << endl << endl;
	d.addVertex(3);
	d.addVertex(4);
	d.addVertex(5);
	d.print();
	//node<int> ** list;
	//list->list_head_insert(0);
		
	return 0;
}

#endif


//#if 0
#include "Sefa_B_HW6_Q1.h"
#include "Sefa_B_HW3.h"
int main(){
	graph<int> * g = new graph<int>(50);
	graph<int> *s = new graph<int>(*g);
	g->addVertex(0); /*Set vertex 0*/
	//cout << "WORK1" << endl;
	g->addVertex(1); 
	//cout << "WORK2" << endl;
	g->addVertex(2);
	//cout << "WORK3" << endl;
	g->addVertex(3);
	//cout << "WORK4" << endl;
	g->addVertex(4);
	//cout << "WORK5" << endl;
	g->addVertex(5);
	//cout << "WORK6" << endl;
	g->addEdge(0, 1,1);
//#if 0
	//cout << "WORK" << endl;
	g->addEdge(2,0, 9);
	//g->addEdge(0,1, 8);
	g->addEdge(0,3, 7);
	//cout << "WORK" << endl;
	g->addEdge(0,5, 6);
//#endif
	//g->removeEdge(2,0);
	/*g->removeEdge(2,0);*//*isConnected works and so does remove.*/
	g->print();
	cout << endl;
	cout << g->numEdges(0) << endl;
	//cout << g->numEdgesTotal() << endl;
	//cout << g->size() << endl;
	//cout << "isC"<< g->isConnected(0,1) << endl;
	size_t size = 0;
	int * neigh = g->neighbors(0, size);
	cout << endl;
	for(size_t i = 0; i < size; i++){
		cout << neigh[i] << " "; 
	}
	cout << endl << endl;
	cout << endl << endl;
	g->print();
	

	//node * h;

	return 0;
}

//#endif
