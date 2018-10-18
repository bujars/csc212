#ifndef __STACK_CPP__
#define __STACK_CPP__

#include "Sefa_B_HW4_Q1.h"



template<class Item>
void stack<Item>::pop(){
	assert(!isEmpty());
	used--;
}

template<class Item>
void stack<Item>::push(const Item& entry){
		data[used] = entry;
}


template<class Item>
void stack<Item>::print(){
	while(!isEmpty()){
		cout << data[used--] << endl;
	}
}


#endif


