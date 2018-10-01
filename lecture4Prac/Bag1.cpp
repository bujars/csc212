#include "Bag1.h"
#ifndef __BAG1_CPP__
#define __BAG1_CPP__
#if 0
#include <iostream>
#include <cassert> /*For assert*/
#include <cstdlib> /*For size_t*/
using namespace std;

	typedef int bagDataType; /*This is just used to rename int*/
#endif
	//const size_t SIZE = 100; /*NOTE the use of size_t will allow us to make sure we never have a negative size.*/
//#endif
	//const std::size_t SIZE;
	Bag1::Bag1(){
		used = 0;
	}
	void Bag1::insert(const bagDataType& num){
		assert(used < SIZE); /*Check to see if our static array has enough capacity to add more elements.*/
		data[used] = num; /*Place the element in the last spot that we know of, ie at used. */
		used++; /*Increment used as  another value has now been added.*/
	}
	size_t Bag1::erase(const bagDataType& num){
		int occurances = 0; /*To count number of values weve erased*/
		for(size_t i = 0; i < used; i++){
			if(data[i] == num){
				occurances++; 
				data[i] = data[used-1]; /*Swap the last value with ith value */
				used--; /*Decrement used so that we aren't looking at the last value that we just swapped*/
				i--; /*Because the last value might have been a num val so we dont want to skip it. */
			}
		}
		return occurances;
	}
	bool Bag1::eraseOne(const bagDataType& num){
		for(size_t i = 0; i < used; i++){
			if(data[i] == num){
				data[i] = data[used-1];
				used--;
				return true;
			}
		}
		return false; 
	}
	void Bag1::operator +=(const Bag1& addend){
		/*What if addend is the same as one being added? make sure used doesnt keep increasing or we will get an infinite loop*/
		assert((addend.used + used) <= SIZE);
		size_t usedB = addend.used;
		for(size_t i = 0; i < usedB; i++){
			data[used] = addend.data[i];
			used++;
		}
	
	}
	size_t Bag1::occurances(const bagDataType& num) const{
		int nums = 0;
		for(size_t i = 0; i < used; i++){
			if(data[i] == num)
				nums++;
		}
		return nums;
	}
	size_t Bag1::totVals() const{
		return used;
	}
	Bag1 operator +(const Bag1& b1, const Bag1& b2){
		assert((b1.totVals()+ b2.totVals()) <= Bag1::SIZE);
		Bag1 Bag; //This is how a bag is declared/ 
		/*for(size_t i = 0; i < b1.totVals(); i++){
			bag.data[i] = b1.data[i];
			bag.used++;
		}
		for(size_t i = 0; i < b2.totVals(); i++){
			bag.data[used+i] = b2.data[i];
			bag.used++;
		}*/
		Bag += b1; /*NOTE we cannot access data for b1 and b2 because thi function is not a member fucntion. But luckily we have += function that does a similar process just step by step*/
		Bag += b2;
		return Bag;
	}






#endif
