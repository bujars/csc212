#ifndef __STACK_CPP__
#define __STACK_CPP__

#include "Sefa_B_HW4_Q1.h"

template<class Item>
stack<Item>::~stack(){
	delete [] data;
	used = 0; /*Reset all other data, even though it wont matter, but it just clears space.*/
	capacity = 0; 
}

template<class Item>
void stack<Item>::push(const Item& entry){
	/*Check if we have enough space*/
	if(used>=size()){
		Item * larger = new Item[++capacity];
		for(size_t i = 0; i < used; i++){
			larger[i] = data[i];
		}
		delete [] data;
		data = larger;
	}
	data[used++]=entry;
}
template<class Item>
bool stack<Item>::isEmpty() const{
	return used == 0;
}
template<class Item>
void stack<Item>::pop(){
	assert(!isEmpty());
	used--;
}

/*NOTE this is kind of not the right way of printing for a stack since its supposed to go backwards, but you get the point.*/
template<class Item>
void stack<Item>::print() const{
	for(size_t i = 0; i < used; i++){
		cout << data[i] << endl;
	}
}

template<class Item>
stack<Item>::stack(const stack<Item>& source){
	/*NOTE no need to check if they are the same because stacks are not the same*/
	capacity = source.capacity;
	used = source.used;
	data = new Item[capacity];
	for(size_t i = 0; i < used; i++){
		data[i] = source.data[i];
	}
}

template<class Item>
void stack<Item>::operator =(const stack<Item>& source){
	/*Check to see if source is the same thing, like y = y*/
	if(this == &source){ /*This is saying, if the address of current pointer, is same as the address of the argument. */
		return; /*Dont do anything if both of their addresses are the same.*/
	}
	used = source.used;
	capacity = source.capacity;
	delete [] data; /*Free up any allocated space. */ 
	data = new Item[capacity];
	for(size_t i = 0; i < used; i++){
		data[i] = source.data[i];
	}
}

template<class Item>
Item stack<Item>::top() const{
	assert(!isEmpty());
	return data[used-1]; /*Just return the last one in the list.*/
}

template<class Item>
void swapStacks(stack<Item>& stack1, stack<Item>& stack2){
	if(&stack1 == &stack2) /*If the two stacks are the same, dont do anything*/
		return;
	stack<Item> s1Temp(stack1);/*else, create a temp stack of one of them*/
	stack1 = stack2; /*Assign one stack to the other*/
	stack2 = s1Temp; /*Assign stack two to temp.*/

}

/*template<class Item>
void stack<Item>::swapStacks(stack& secondStack){
	this = secondStack;
}*/

#endif
