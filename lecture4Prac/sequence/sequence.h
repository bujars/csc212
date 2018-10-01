#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__



#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class sequence{
	
		
	public:
		/*TYPEDEFS AND MEMBER CONSTANTS*/	
		typedef double value_type; 
		/*Easy to just change the type of sequence here*/
		typedef size_t size_type;  
		/* This is how the book does it:   typedef std::size_t size_type;*/
		static const size_type CAPACITY = 30;
		/*CONSTRUCTOR*/
		sequence() {used=0; current_index = 0;}; /*Set used = 0 because no entries and set index to the first index. */
		/*MODIFICATION MEMBER FUNCTIONS*/
		void start();
		void advance();
		value_type current() const;
		bool is_item() const;
		void shiftEntriesRight(const size_t& index);
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void remove_current();
#if 0
		/*TYPEDEFS AND MEMBER CONSTANTS*/	
		typedef double value_type; 
		/*Easy to just change the type of sequence here*/
		typedef size_t size_type;  
		/* This is how the book does it:   typedef std::size_t size_type;*/
		static const size_type CAPACITY = 30;
#endif

	private:
		value_type data[CAPACITY];
		size_type used;
		size_type current_index;
#if 0
	public:
		/*CONSTRUCTOR*/
		sequence() {used=0; current_index = 0;}; /*Set used = 0 because no entries and set index to the first index. */
		/*MODIFICATION MEMBER FUNCTIONS*/
		void start();
		void advance();
		value_type current() const;
		bool is_item() const;
		void shiftEntriesRight(const size_t& index);
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void remove_current();

#endif
};

#endif
