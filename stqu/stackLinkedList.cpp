#ifndef __STACK_CPP__
#define __STACK_CPP__

#include "stackLinkedList.h"

stack::stack(){
	topPtr = NULL;
}

bool stack::isEmpty() const{
	return (topPtr == NULL);
}

size_t stack::size(){ //const{ /*NOTE not const because I didn't implement it to be constant.*/
	return list_length(topPtr);/*Iterate through list counting nodes*/
}

void stack::push(const int& entry){
	list_head_insert(topPtr, entry); /*Keep inserting at head to keep track of last.*/
}


int stack::top() const{
	assert(!isEmpty()); /*Check if we have list*/
	return topPtr->data(); /*return head which points to last element*/
}

void stack::pop(){
	assert(!isEmpty()); /*Make sure we have a list, otherwise we cant pop.*/
	list_head_remove(topPtr); /*Remove head since it was last one in, and must be first one out.*/
}

void stack::print(){
	list_print(topPtr);
}


#endif
