#include "Sefa_B_HW3.h"

int main(){
	
	//node * bit = NULL;
	//list_head_insert(bit, 2);
	node * bit;
	//cout  << bit->link();
	//cout << bit->data();
	node *head = NULL;//new node();

	list_head_insert(head , 7);
	//list_head_insert(bit, 7);
	cout << "PRINT" << endl;
	list_print(head);
	
//#if 0 	
	cout << endl;
	list_end_insert(head, 8);
	list_print(head);
	cout << endl;
	list_end_insert(head, 3);
	list_print(head);
	cout << endl;
	list_head_insert(head, 4);
	list_end_remove(head);
	list_end_remove(head);
	list_end_insert(head, 6);
	list_end_insert(head, 99);
	//list_head_insert(head,4);
	list_print(head);
	cout << endl << endl;

	node *head_ptr = new node(); //Initialize head_pointer to nothing.
	cout << "LENGTH: " << list_length(head_ptr) << endl;
	//node *second = new node(2, NULL);
	//node *third = new node(3, NULL);

	//cout << second->data() << endl;
	//list_head_insert(head_ptr, 0);
	head_ptr->set_data(20);
	cout << head_ptr->data() << endl;


	cout << "NEW HEAD  " << endl << endl;
	list_head_insert(head_ptr, 2);
	//list_end_remove(head_ptr);
	list_print(head_ptr);
	//cout << head_ptr << endl;
	//cout << head_ptr->data() << " " << head_ptr->link() << endl;

//	cout << NULL << endl;

//	#if 0	
 	//cout << "Fail" << endl;
	node * sec = head_ptr->link(); /*I think this starts to*/
	//cout << "fail 1" << endl;
	//cout << sec << endl;
	//cout << sec->data() << endl;
	//node * j = new
	
	//list_insert(NULL, 0);
	//cout << "make" << endl;
	//list_print()


	/*Yes, it is failing because of null call. Null doesn't point to anything. Not sure if this is a pre-condition that needs to be checked or not. Like to elaboorate more, there is no where for it to link with pointers, it technically becomes the first pointer but doesn't actually save. I am not too sure why this occurs. Need elaboration - > post exam. */
	list_insert(sec, 3); /*I am not sure if this is failing because i call link from NULL?*/
	//cout << "fail 2"<< endl;
	node * thr = sec->link();
	list_insert(thr, 10);
	node * fot = thr->link();
	//cout << fot->data() << endl;
	list_print(head_ptr);
	cout << "LENGTH: " << list_length(head_ptr) << endl;

	node * found = list_locate(head_ptr, 4);
	cout << "ISFOUND: "<< found->data() << endl;
	found = list_locate(head_ptr, 1);
	cout << "ISFOUND: " << found->data() << endl;
	
	cout << endl <<endl<<endl;
	list_head_remove(head_ptr);
	cout << "Head removed: " << endl;
	list_print(head_ptr);
	cout << endl << endl << endl;
	//cout << fot->data() << endl;
	cout <<endl << endl << "removing thr " << endl;
	list_remove(thr); /*NOTE this actually fails if you provide the very last pointer? Segmutation dumped?*/
	//cout << fot->data() << endl; /*NOTE out pointer for node with data of 10 still exists, its just no longer part of the linkedlist*/
	//cout << fot->link() << endl;
	
	list_print(head_ptr);




	cout << endl << endl << endl << "Adding new last item 5" << endl;
	list_insert(thr, 5); /*NOTE fot is forever lost since it was removed. */
	list_print(head_ptr);

	cout << endl <<endl<< endl << "Removing end" << endl;
	list_end_remove(head_ptr);
	list_print(head_ptr);


	cout << endl << endl << "TESTING SWAP I I+1 past position. SHouldn't do anything." << endl;
	list_swap_next(head_ptr, 10);
	list_print(head_ptr);

	cout << endl << "CLEARING: " << endl;
	list_clear(head_ptr);
	list_print(head_ptr);
	cout << "END" << endl << endl;


	cout << "Starting new list for other functions " << endl;
	node * newH = new node();//new node();
	list_ith_insert(newH, 1, 1);
	node * f = newH->link();
	list_insert(f, 2);
	node * s = f->link();
	list_insert(s, 3);
	node * t = s ->link();
	list_insert(t, 4);
	node * r = t->link();
	list_end_insert(newH, 5);
	node * e = r->link();
	cout << "Printing List" << endl;
	list_print(newH);
	cout << "LENGHT: " << list_length(newH) << endl;
#if 0 
	list_ith_remove(newH, 1);
	list_print(newH);
	list_ith_remove(newH, 5);
	list_print(newH);
	list_ith_remove(newH, 10);
	list_print(newH);
#endif
	cout << endl<<endl<<"Adding using position add" << endl;
	list_ith_insert(newH, 100, 0);
	list_ith_insert(newH, 99, 10);
	list_ith_insert(newH, 87, 4);
	list_ith_insert(newH, 22, 3);
	//list_ith_remove(newH, 0);
	list_print(newH);
	cout << "LENGTH" << list_length(newH) << endl;
	cout << endl<< endl << "TESTING search: " << endl;
	int tar = 101;
	node * ser= list_search(newH, tar);
	//cout << ser->data() << endl;
	/*Is going to give an error because out of bounds...*/
	//list_head_insert(newH, 15);
	//list_print(newH);




	//#endif
	
	cout << "MAKING A CYCLE" << endl;
	node * start = new node();
	list_end_insert(start, 1);

	node * f1 = start->link();
	list_end_insert(start, 2);
	node * b1 = f1->link();//new node(2, f1);
	list_end_insert(start, 3);
	node * c1 = b1->link();//new node(3, b1);
	list_end_insert(start, 4);
	node* d1 = c1->link();//new node(4, c1);
	list_end_insert(start, 5);
	node * e1 = d1->link();//new node(5, d1);
	list_print(start);

	

	cout << endl << endl << "TESTING SWAP I I+1 past position. SHouldn't do anything." << endl;
	//list_swap_next(start, 3);
	list_print(start);

	
	/*cout << "errror here" << endl;	*/
	
	//e1->set_link(f1);
	//list_print(start);
	/*cout << "HERE??!" << endl;*/
	/*cout << "errrrrrrrrr" << endl;*/
	bool isCycle = list_cycle(start);
	cout << endl << endl << endl << "CYCLE IS: " << isCycle << endl;

	/*cout << endl << endl << "Testing reverse" << endl;
	list_clear(start);
	list_reverse(start);
	list_print(start);*/
		
	cout << endl << endl << "TESTING SWAP I J" << endl;
	list_swap_IJ(start, 3, 5);
	list_print(start);
	cout << endl << endl;


	
	cout << "TESTING OVERLOADING" << endl;
	node *bj = new node(99, NULL);
	list_head_insert(start, bj);
	list_print(start);
	list_end_insert(start, bj);
	list_ith_insert(start, bj, 9);
	cout << endl << endl;
	list_print(start);
//#endif
	return 0;
}
