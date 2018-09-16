#include "Bag1.h"
#ifndef __BAG1_CPP__
#define __BAG1_CPP__

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

	typedef int bagDataType;
	const size_t SIZE = 100;

	Bag1::Bag1(){
		used = 0;
	}
	void insert(const bagDataType& num){
	}
	size_t Bag1::erase(const bagDataType& num){
		int occurances = 0;
		return occurances;
	}
	void Bag1::eraseOne(const bagDataType& num){
	}
	void Bag1::operator +=(const Bag1& addend){
	}
	size_t Bag1::occurances(const bagDataType& num) const{
		int nums = 0;
		return nums;
	}
	size_t Bag1::totVals() const{
		return used;
	}
	Bag1 operator +(const Bag1& b1, const Bag1& b2){
		//Bag1 bag();
		return b1;
	}






#endif
