#ifndef __STACK_CPP__
#define __STACK_CPP__

#include "Sefa_B_HW4_Q5.h"

template<class Item>
void stack<Item>::push(const Item& entry){
	//stackHolder->push(entry);
	/*Move everything from holder to temp.*/
	/*while(!stackHolder->empty()){
		stackTemp->push(stackHolder->front());
		stackHolder->pop();
	}*/
	stackTemp->push(entry); /*Add new to temp.*/
	/*while(!stackTemp->empty()){
		stackHolder->push(stackTemp->front());
		stackTemp->pop();
	}*/

	/*NOTE:::: THe following is for deleting.*/
	/*If stacks next first is == last, then just remove that position...? Iterate till you get to second to last, pop that off, then move everything back into q1?...We also have size >1 because we can access the size of it. */
}



#endif
