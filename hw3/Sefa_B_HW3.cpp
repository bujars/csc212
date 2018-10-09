#include "Sefa_B_HW3.h"
#ifndef __NODE_CPP__
#define __NODE_CPP__
	void list_head_remove(node*& head_ptr){
		if(head_ptr == NULL)
			return;
		node* remove_ptr;
		remove_ptr = head_ptr; /*Set node to remove to our current head*/
		head_ptr = head_ptr->link(); /*Make head look at the second node*/
		delete remove_ptr; /*remove old head*/
	}
	void list_remove(node* previous_ptr){
		/*if(pre)//Do i check for this here???>..... cause I dont check in insert*/
		node* remove_ptr;
		remove_ptr = previous_ptr->link(); /*Create a new node that points to current*/
		previous_ptr->set_link(remove_ptr->link()); /*Make previous node point to next*/
		delete remove_ptr; /*delete current*/
	}

	/*NOTE: Question, originally have pos - i for list_locate, 
	 * but then read piazza comment where it said if pos is 3, it gives fourht node. 
	 * Just incase I was orgininally right, I made this last switch because of mis understanding.*/
	void list_ith_remove(node* head_ptr, const size_t& i){
		/*First check if i is actually in the list*/
		/*if(!(i < list_length(head_ptr)))
			return;*/
		//assert(i > 0); /*Must give a position greater than 0 as head points to 1*/ /*NOTE GOT RID OF THIS because pos starts at 0*/
		size_t pos = i; /*Renaming pos to i so that we can set i to last since its const*/
		/*for(node * cursor = head_ptr)*/
		/*NOTE use list_locate to get the previous node!!*/
		/*assert(i <= list_length(head_ptr));*/
		size_t len = list_length(head_ptr);
		if(pos>len){
			pos = len; /*Set to last position.*/
		}
		if(head_ptr == NULL)
			return;
		 if(pos == 0){ //Because head_ptr is at first position / /NOTE: This might need to be updated now since head is 0 and ifrst is 1, so wouldnt want to place in 0th. changed position to 0 instead.../
			list_remove(head_ptr);
			return;
		}
		node * beforeIth = list_locate(head_ptr, pos);/*NOT sure if its i or i-1 since head is usually 1? I think it is 1 because locate says head_ptr starts at 1...*/
		if(beforeIth != NULL) /*Not sure if I need this check?*/
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
		for(cursor; cursor->link()!=NULL; cursor = cursor->link()){ 
			/*NOTE how we check if the next one is not null, 
			 * this is because we are moving the pointer twice to hit null with one, 
			 * and save the previous, or last pointer that is to be removed.*/
			end = cursor; 
		}
		end->set_link(NULL);/*Set previos to NULL*/
		delete cursor; /*Remove last*/

	
	}

	void list_insert(node* previous_ptr, const node::nodeDataType& entry){
		/*assert(previous_ptr->link() != NULL);*/ /*Cannot use this if first node is head node....
		 but not sure why it wont work if you just pass null in. */
		/*//cout << previous_ptr->data() << " " << previous_ptr->link() << endl;
		//cout << entry << endl;*/
		/*Im assuming if its null, just call head pointer???*/

		/*The function that calls this checks for null pointers*/
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
		/*cout << "HERE" << endl;*/
	
	}
	/*Note *& incase someone wants to insert at head.*/
	void list_ith_insert(node *& head_ptr, const node::nodeDataType& entry, const size_t& pos){
		//assert(pos > 0); /*Because first node starts at position 1 --> as seen in  locate function*/
		size_t len = list_length(head_ptr);
		size_t i = pos;
		if(head_ptr == NULL || pos ==0){
			list_head_insert(head_ptr, entry);
			return;
		}
		if(i > len){
			i = len;
		}
		node * add = list_locate(head_ptr, i);/*NOTE i-1 to find previous to use insert*/
		list_insert(add, entry);
	}




	/*NOTE: Head_ptr is technically counted as the first node!*/
	size_t list_length(const node* head_ptr){
		size_t length = 0;
		for(const node* cursor = head_ptr; cursor != NULL; cursor = cursor->link()){
			length++;
		}
		return length;
	}

	node* list_locate(node * head_ptr, const size_t& position){
		node * cursor = head_ptr;
		assert(0 < position); //&& position > list_length(head_ptr)); /*//&& !(position < list_length(head_ptr)));*/
		/*if(position >= list_length(head_ptr)){
			return ret;
		}*/
		size_t i = 1; /*NOTE start from 1 because thats where head_ptr starts.*/
		for(i; i< position && cursor!=NULL; i++){
			cursor=cursor->link();
		}
		return cursor;
	}

	const node* list_locate(const node* head_ptr, const size_t& position){
		const node * cursor = head_ptr;
		assert(0 < position); //&& position > list_length(head_ptr)); /*//&& !(position < list_length(head_ptr)));*/
		/*if(position >= list_length(head_ptr)){
		 * 			return ret;
		 * 					}*/
		size_t i = 1; /*NOTE start from 1 because thats where head_ptr starts.*/
		for(i; i< position && cursor!=NULL; i++){
			cursor=cursor->link();
		}
		return cursor;
	}

	void list_clear(node*& head_ptr){
		while(head_ptr!=NULL){
			list_head_remove(head_ptr); /*go through the list removing the first node each time*/
		}
	}

	/*Not clear at all on how head_ptr should be printed or not.*/
	void list_print(const node* head_ptr){
		if(head_ptr == NULL)
			return;
		/*for(const node* cursor = head_ptr->link(); cursor!=NULL; cursor = cursor->link()){
			cout << cursor->data() << endl;
		}*/
		/*Not sure which version is right*/
		for(const node* cursor = head_ptr; cursor!=NULL; cursor = cursor->link()){
			cout << cursor->data() << endl; 
			cout << cursor->link() << endl;
		}							
	}
	
	/*HOW TO CHECK NULL?*/
	node * list_search(node* head_ptr, const node::nodeDataType& target){
		if(head_ptr == NULL){ /*If no list, return NULL --> doesn't need to be checked since for loop handles this*/
			return NULL;
		}
		for(node* cursor = head_ptr; cursor!=NULL; cursor = cursor->link()){
			if(cursor->data() == target) /*If we find what we are looking for,return*/
				return cursor;
		}
		return NULL; /*If didn't find anything, return NULL*/
	}
	
	/*Same as above function excpet all nodes are declared as const so that nothing can be changed.*/
	const node* list_search(const node* head_ptr, const node::nodeDataType& target){
		if(head_ptr == NULL)
			return NULL;
		for(const node* cursor = head_ptr; cursor!=NULL; cursor = cursor->link()){
			if(cursor->data() == target) /*If we find what we are looking for,return*/
				return cursor;
			}
		return NULL;	
	}


	/* Have two nodes, one that moves by 1 link, the other that moves by two links, as long as none are null, keep going around.
	 * First think to check is that head actually points to soemthing, and that first and second ones aren't null. 
	 * If thats the case, no cycle. then keep going until both nodes are at the same spot which form a cycle - Liu*/
	bool list_cycle(const node* head_ptr){
		if(head_ptr == NULL || head_ptr->link() == NULL || head_ptr->link()->link() == NULL){
			return false;
		}
		/*cout << "deonte" << endl;*/
		const node * firstCursor = head_ptr;
		const node * secondCursor = head_ptr->link();
		secondCursor = secondCursor->link(); /*Could have started these before*/
		while(secondCursor != NULL && firstCursor != NULL){
			/*cout << "jjj" << endl;*/
			if(secondCursor == firstCursor)
				return true;
			secondCursor = secondCursor->link();
			if(secondCursor == NULL) /*Because doing two links might just make it null overall.*/
				return false;
			secondCursor= secondCursor->link();
			firstCursor = firstCursor->link();
		}
		/*cout << "here? " << endl;*/
		return false;
	}


	void list_swap_next(node*& head_ptr, const std::size_t& i_pos){
		size_t len = list_length(head_ptr); /*O(n)*/
		if(i_pos+1>len-1 || len < 2)/*Becuase I am checking if we have i and next spot*/
			return;
		if(head_ptr == NULL || head_ptr->link() == NULL){ /*This means list is less than len 1*/
			return;
		}
		if(i_pos == 0){
			node * iNext = head_ptr->link();
			head_ptr->set_link(iNext->link());
			list_head_insert(head_ptr, iNext->data());
			delete iNext; 
			return;
		}
		node * i_previous = list_locate(head_ptr, i_pos);/*Locate node before because we need the link. CHANGE THE i-1.... Not sure why but i think its cause had is at 0 yet is still finds that first val*/
		node * i_node = i_previous->link();
		if(i_previous->link() == NULL || i_node->link()==NULL)
			return; /*Dont have sufficent nodes. NOTE this check might be repetative since we already checked pos+1 len... sooo might not need.*/
		node * i_next = i_node->link();
		node * temp = i_node;
		i_previous->set_link(i_next);
		i_node->set_link(i_next->link());
		i_next->set_link(temp);
	}


		void list_reverse(node*& head_ptr){
			node* reversed = NULL;
			for(node*cursor = head_ptr; cursor!=NULL; cursor=cursor->link())
				list_head_insert(reversed, cursor->data());
			/*After all is reversed, set head to start*/
			head_ptr = reversed;
		}






#endif
