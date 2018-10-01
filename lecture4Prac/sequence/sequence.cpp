#include "sequence.h"
#ifndef __SEQUENCE_CPP__
#define __SEQUENCE_CPP__

#if 0
#include <iostream>
#include <cassert> /*For assert*/
#include <cstdlib> /*For size_t*/
using namespace std;
#endif

//	typedef double value_type;
//	typedef size_t size_type; 	
	/*This is now book does it:  typedef std::size_t size_type; */
#if 0	
	/*Only include static in header file not in implementation file.*/
	const size_type CAPACITY = 30;
#endif
/*This sets the index == 0*/
void sequence::start(){
	current_index = 0;
}

/*This function returns the current index. Note it checks is_item first to make sure we actually have a current item*/
sequence::value_type sequence::current() const{
	/*if(this->is_item())
		return data[current_index];
	return 0; //Return 0 nothing... don't know how to go about checking this. 
*/
	assert(is_item());
	return data[current_index];
}

/*This checks if a current item is present, if that is the case, increase our current index to be looked at*/
void sequence::advance(){
	assert(is_item());
	current_index++;
}

/*NOTE this just checks if we have a current item*/
bool sequence::is_item() const{
	if(current_index < used){
		return true;
	}
	return false;
}

/*NOTE this is a helper method that is used in insert and attach --
 * can potentially be used for remove_current if some parameters change.
 *
 * Maybe it would be better to make as a friend function -- 
 * or remove it altogether and just have each individual function handle it*/

void sequence::shiftEntriesRight(const size_t& index){
	assert(used < CAPACITY);
	for(size_t i = used; i > index; i--){
		data[i] = data[i-1];
	}
}

#if 0
void sequence::insert(const value_type& entry){
	assert(used < CAPACITY);
	/*if(current_index == 0){
		data[0] = entry;
		used++;
		return;
	}*/
	if(!is_item()){
		current_index = 0; 
	}
	else{ /*NOTE since you have return you don't really need this else*/
		shiftEntriesRight(current_index);
		data[current_index] = entry;
		used++;
	}
}
#endif

void sequence::insert(const value_type& entry){
	assert(used < CAPACITY);
	if(!is_item()){
		current_index = 0; /*NOTE this is so that if we dont have a current item, we place it at the front*/
	}
	shiftEntriesRight(current_index);
	data[current_index] = entry;
	used++;

}


void sequence::attach(const value_type& entry){
	assert(used<CAPACITY);
	if(!is_item()) /*Why did this if just fix everything?...It is saying that if our index is the same value as the amount we entered in total, ie used, then we want to move one place back, ie the last index. this way we cna then increase it to the next index again but this time place values there? .*/
		current_index = used-1;
	/*NOTE current index gets shifted right away so that it doesn't need to be incremented after each call*/
	//current_index++;
	current_index++;
	shiftEntriesRight(current_index);
	data[current_index] = entry;
	//current_index+1;
	used++;
}

void sequence::remove_current(){
	assert(is_item());	/*assert(is_item() && current_index!=0);*/ 
	for(size_t i = current_index; i < used-1; i++){ 
		/*NOTE used-1 handles that if we are in the first spot. */
		data[i] = data[i+1]; /*NOTE originally had i++ which would not keep everything in order.*/
	}
	if(used > 0){
		used--;
	}
}


#endif
