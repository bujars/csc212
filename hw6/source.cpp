#if 0

#include "Sefa_B_HW6_Q4.cpp"
int main(){
	return 0;
}
#endif

#if 0
#include "Sefa_B_HW6_Q2.h"
#include "node2.h"
int main(){
	graph<int> d;//(30);// = new graph<int>(30);
//#if 0
	graph<int> e;
	d.addVertex(2);
//#if 0
	d.print();
	cout << endl << endl;
//#if 0
	d.addVertex(3);
	d.addVertex(4);
	d.addVertex(5);
	d.print();
	cout << endl << endl;
//#if 0
	cout << "Connected "<< d.isConnected(0,1)<<endl;
//#if 0
	d.addEdge(0 ,1, 10);
	d.addEdge(0 ,2, 20);
	d.addEdge(0 ,3, 30);
	d.addEdge(1 ,2, 40);	
	d.addEdge(1 ,3, 50);
	d.addEdge(1 ,0, 60);
	cout << endl << endl; 
	cout << "Connected " << d.isConnected(0,1)<<endl;	
	d.print();
	cout << endl << endl;
	cout << "erre" << endl;
	d.removeEdge(0,1);
	cout << "Connected " << d.isConnected(0,1)<<endl;
	d.print();
#if 0
	//cout << d.getWeight(0,1) << endl; //for Q1
	//node<int> ** list;
	//list->list_head_insert(0);
#endif
	cout << endl << endl;
	size_t size = 0;
	int * neigh = d.neighbors(1, size);
	for(size_t i =0; i < size; i++){
		cout << neigh[i] << endl;
	}
	
	cout << endl << endl << d.numEdgesTotal() << endl << endl << d.numEdges(2) << endl;

	cout << "L " << endl;
	e = d;
	e.print();
 	cout << endl << endl << "B" << endl;
	graph<int> b(e);
	b.print();


	return 0;
}

#endif


//#if 0
#include "Sefa_B_HW6_Q1.h"
//#include "Sefa_B_HW3.h"
//#include "Sefa_B_HW6_Q3.cpp"
//#include "Sefa_B_HW6_Q3.h"
//#include "Sefa_B_HW6_Q4.cpp"
#include "kazi.cpp"
int main(){
#if 0
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
	g->removeEdge(2,0);
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

	cout << "printed??" << endl;
	cout << endl << endl;
	cout << endl << endl;
	g->print();
	
	cout << endl << endl << g->getWeight(0,3) << endl;

	//node * h;
#endif

	/*Testing Q3*/
	cout << endl << endl << "TESTING Q3" << endl ;
	graph<int> dfs;
	dfs.addVertex(0);
	dfs.addVertex(1);
	dfs.addVertex(2);
	dfs.addVertex(3);
	dfs.addVertex(4);
	dfs.addVertex(5);
 	dfs.addEdge(0, 1, 4);
    dfs.addEdge(0, 2, 3);
	dfs.addEdge(1, 3, 2);
	dfs.addEdge(1, 2, 5);
	//dfs.addEdge(2,0, 10);
	dfs.addEdge(2, 3, 7);
	dfs.addEdge(3, 4, 2);
	dfs.addEdge(4, 0, 4);
	//dfs.addEdge(4, 1, 4);
	//dfs.addEdge(4, 5, 6);
	//cout << "fail here?";
	dfs.print();
	const size_t index = 0;
	bool r =cycleDepthFirst(dfs, 0);
	cout << "KAZI "<<r << endl;
	
	
	
	/*
	depthFirst(dfs, index);
	breadthFirst(dfs, index);	

	graph<int> bfs(dfs);
	cout << endl << endl;
	bfs.print();
	graph<int> o;
	o = bfs;
	cout << endl << endl;
	o.print();
	//cout << "?????" << endl;
	//return 0;
	
	dijkstra(dfs, 0);*/
	return 0;
}

//#endif
