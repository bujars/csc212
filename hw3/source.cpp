#include "Sefa_B_HW3.h"

int main(){

	list_head_insert(NULL, 2);
	node *head_ptr = new node(); //Initialize head_pointer to nothing.
	cout << "LENGTH: " << list_length(head_ptr) << endl;
	//node *second = new node(2, NULL);
	//node *third = new node(3, NULL);

	//cout << second->data() << endl;
	//list_head_insert(head_ptr, 0);
	head_ptr->set_data(20);
	cout << head_ptr->data() << endl;

	list_insert(head_ptr, 2);
	node * sec = head_ptr->link();
	list_insert(sec, 3);
	node * thr = sec->link();
	list_insert(thr, 10);
	node * fot = thr->link();
	cout << fot->data() << endl;
	list_print(head_ptr);
	cout << "LENGTH: " << list_length(head_ptr) << endl;

	node * found = list_locate(head_ptr, 4);
	cout << "ISFOUND: "<< found->data() << endl;
	found = list_locate(head_ptr, 1);
	cout << "ISFOUND: " << found->data() << endl;
	
	
	list_head_remove(head_ptr);
	cout << fot->data() << endl;
	list_remove(thr); /*NOTE this actually fails if you provide the very last pointer? Segmutation dumped?*/
	cout << fot->data() << endl; /*NOTE out pointer for node with data of 10 still exists, its just no longer part of the linkedlist*/
	cout << fot->link() << endl;
	
	list_print(head_ptr);
	
	list_insert(thr, 5); /*NOTE fot is forever lost since it was removed. */
	list_print(head_ptr);
	
	return 0;
}
