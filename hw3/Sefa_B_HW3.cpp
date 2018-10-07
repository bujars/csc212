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

	void list_head_insert(node*& head_ptr, const node::nodeDataType& entry){
		head_ptr = new node(entry, head_ptr);
	}

	void list_insert(node* previous_ptr, const node::nodeDataType& entry){
		node* insert_ptr = new node(entry,previous_ptr->link());
		previous_ptr->set_link(insert_ptr);
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
		assert(0 < position); //&& !(position < list_length(head_ptr)));
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
	
		for(const node* cursor = head_ptr; cursor!=NULL; cursor = cursor->link()){
			cout << cursor->data() << endl;
		}
	}


#endif
