#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__



#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class sequence{
	//TYPEDEFS AND MEMBER CONSTANTS
	typedef double value_type;
	typedef std::size_t size_type;
	static const size_type CAPACITY = 30;

	private:
		value_type data[CAPACITY];
		size_type used;
		size_type current_index;
	
	public:
		//CONSTRUCTOR
		sequence() {used=0;}
		//MODIFICATION MEMBER FUNCTIONS
		void start();
		void advance();
		value_type current() const;
		bool is_item() const;


};

#endif
