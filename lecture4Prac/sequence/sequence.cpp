#include "sequence.h"
#ifndef __SEQUENCE_CPP__
#define __SEQUENCE_CPP__

#include <iostream>
#include <cassert> /*For assert*/
#include <cstdlib> /*For size_t*/
using namespace std;

	typedef double value_type;
	typedef std::size_t size_type;
	const size_type CAPACITY = 30;


void sequence::start(){
	current_index = 0;
}

value_type sequence::current() const{
	if(this->is_item())
		return data[current_index];
	return 0; //Return 0 nothing... don't know how to go about checking this. 
}


void sequence::advance(){
	if(this->is_item()){
		current_index++;
	}
}

bool sequence::is_item() const{
	if(current_index < used){
		return true;
	}
	return false;
}

#endif
