#ifndef __STACK_H__
#define __STACK_H__

#include "Sefa_B_HW3.h"


/*NOTE no need for template because was never initialized as a template class.*/
/*template<class Item>*/
class stack{
	public:
		stack();
		void pop();
		void push(const int& source);
		size_t size(); //NOTE, isn't const in my implementation //const;
		int top() const;
		bool isEmpty() const;
		void print();
	private:
		node * topPtr;
};


#endif
