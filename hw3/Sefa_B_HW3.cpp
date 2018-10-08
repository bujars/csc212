#include "Sefa_B_HW3.h"
#ifndef __NODE_CPP__
#define __NODE_CPP__
	void list_head_remove(node*& head_ptr){
		node* remove_ptr;
		remove_ptr = head_ptr; /*Set node to remove to our current head*/
		head_ptr = head_ptr->link(); /*Make head look at the second node*/
		delete remove_ptr; /*remove old head*/
	}
	void list_remove(node* previous_ptr){
		node* remove_ptr;
		remove_ptr = previous_ptr->link(); /*Create a new node that points to current*/
		previous_ptr->set_link(remove_ptr->link()); /*Make previous node point to next*/
		delete remove_ptr; /*delete current*/
	}


	void list_ith_remove(node* head_ptr, const size_t& i){
		/*First check if i is actually in the list*/
		/*if(!(i < list_length(head_ptr)))
			return;*/

		/*for(node * cursor = head_ptr)*/
		/*NOTE use list_locate to get the previous node!!*/
		assert(i > 0);
		if(i == 1){
			list_remove(head_ptr);
			return;
		}
		node * beforeIth = list_locate(head_ptr, i-1);
		if(beforeIth != NULL)
			list_remove(beforeIth);
										 
	}



	void list_head_insert(node*& head_ptr, const node::nodeDataType& entry){
		/*cout << "here2"<<endl;*/
		head_ptr = new node(entry, head_ptr);
	}


	/*NOT SURE IF IT WORKS*/
	void list_end_remove(node*& head_ptr){
		/*Check if nothing in head, since we need previous to work for list_remove*/
		if(head_ptr == NULL){
			return;
		}
		/*Second edgecase, check if we are in the second to last positiion*/
		if(head_ptr->link()==NULL){
			head_ptr->set_link(NULL);
			delete head_ptr->link(); /*Remove last*/
			return;
		}
		
		node * end = head_ptr;
		node * cursor = head_ptr;
		for(cursor; cursor->link()!=NULL; cursor = cursor->link()){ /*NOTE how we check if the next one is not null, this is because we are moving the pointer twice to hit null with one, and save the previous, or last pointer that is to be removed.*/
			end = cursor; 
		}
		end->set_link(NULL);/*Set previos to NULL*/
		delete cursor; /*Remove last*/

	
	}

	void list_insert(node* previous_ptr, const node::nodeDataType& entry){
		/*assert(previous_ptr->link() != NULL);*/ /*Cannot use this if first node is head node....but not sure why it wont work if you just pass null in. */
		/*//cout << previous_ptr->data() << " " << previous_ptr->link() << endl;
		//cout << entry << endl;*/
		/*Im assuming if its null, just call head pointer???*/
		node* insert_ptr = new node(entry,previous_ptr->link());
		previous_ptr->set_link(insert_ptr);
	}

	/*NOTE the *& is needed to be able to check for empty case and create new head if needed. */
	void list_end_insert(node *& head_ptr, const node::nodeDataType& entry){
		/*Check if head_ptr has nothing -- NOT sure about this yet since we didn't check in insert*/
		if(head_ptr==NULL){/*NOTE this doesn't work without *& because it cannot set up a new head*/
			/*cout << "here" << endl;*/
			list_head_insert(head_ptr, entry);/*Make a new head and save it*/
			/*cout << "hereL" << endl;*/
			return;
		}
		node * cursor = head_ptr;
		for(cursor; cursor->link()!=NULL; cursor = cursor->link()){
		}
		list_insert(cursor, entry);
		cout << "HERE" << endl;
	
	}
	
	size_t list_length(const node* head_ptr){
		size_t length = 0;
		for(const node* cursor = head_ptr; cursor != NULL; cursor = cursor->link()){
			length++;
		}
		return length;
	}

	node* list_locate(node * head_ptr, const size_t& position){
		node * ret = NULL;
		node * cursor = head_ptr;
		assert(0 < position); /*//&& !(position < list_length(head_ptr)));*/
		/*if(position >= list_length(head_ptr)){
			return ret;
		}*/
		size_t i = 1; /*NOTE start from 1 because thats where head_ptr starts.*/
		while(cursor!=NULL){
			if(i==position){
				ret = cursor;
				return ret;
			}
			i++;
			cursor=cursor->link();
		}
		return ret;
	}

	const node* list_locate(const node* head_ptr, const size_t& position){
		return head_ptr;
	}

	void list_clear(node*& head_ptr){
		while(head_ptr!=NULL){
			list_head_remove(head_ptr); /*go through the list removing the first node each time*/
		}
	}

	void list_print(const node* head_ptr){
		if(head_ptr == NULL)
			return;
		for(const node* cursor = head_ptr->link(); cursor!=NULL; cursor = cursor->link()){
			cout << cursor->data() << endl;
		}
	}


#endif
