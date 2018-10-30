#ifndef __STACK_CPP__
#define __STACK_CPP__

#include "Sefa_B_HW4_Q5.h"

template<class Item>
stack<Item>::stack(size_t init_cap){
	stackHolder = queue<Item>(init_cap);
	stackTemp = queue<Item>(init_cap);
}

template<class Item>
stack<Item>::~stack(){
	
}

template<class Item>
stack<Item>::stack(const stack<Item>& source){
	stackHolder = queue<Item>(source.stackHolder);
	stackTemp = queue<Item>(source.stackTemp);
}

template<class Item>
void stack<Item>::operator=(const stack<Item>& source){
	/*Check if its the same thing*/
	if(this == &source){
		return;
	}
	/*CALL the assignment operator from stack which handles everything it needs to.*/
	stackHolder = source.stackHolder;
	stackTemp = source.stackTemp;


}

template<class Item>
bool stack<Item>::isEmpty() const{
	/*Call the queue's empty function.*/
	return stackHolder.empty();
}

template<class Item>
size_t stack<Item>::size() const{
	return stackHolder.size();
}


template<class Item>
Item stack<Item>::top(){
	/*NOTE below doesnt work since stackHolder holds everything in order, */
	/*return stackHolder.front();*/
	/*Let's make sure we aren't empty.*/
	assert(!stackHolder.empty());
	/*cout << "WTF" << endl;*/
	Item ret = Item(); /*Return the default if nothing.*/
	/*Move everything but last element.*/
	/*cout << "HERE" << endl;*/
	while(stackHolder.size()!=1){/*NOTE check size is up to 1 because want to return last one.*/
		/*cout << "HOlLDER Front " << stackHolder.front() << endl;*/
		stackTemp.push(stackHolder.front());
		/*cout << "TEMP Front " << stackTemp.front() << endl;*/
		stackHolder.pop();
	}
	/*cout << "HERE2 " << endl;*/
	/*Store front "last item" to return*/
	ret = stackHolder.front();
	/*Get rid of last item*/
	stackHolder.pop();
	/*Put everything back into the queue that holds the stack.*/
	while(!stackTemp.empty()){
		/*cout << "TEMP Front " << stackTemp.front() << endl;*/
		stackHolder.push(stackTemp.front());
		/*cout << "HOlLDER Front " << stackHolder.front() << endl;*/
		stackTemp.pop();
	}
	/* NOTE NOTE NOTE PLACE BACK THE ORIGINAL AT THE END.*/
	stackHolder.push(ret);
	return ret;

}

/*Push everything into temp, then push everything into holder. */

template<class Item>
void stack<Item>::push(const Item& entry){
	//stackHolder->push(entry);
	/*Move everything from holder to temp.*/
	/*while(!stackHolder->empty()){
		stackTemp->push(stackHolder->front());
		stackHolder->pop();
	}*/

	/*NOTE NOTE NOTE everything just linerally pushes into queue called stack Holder and then popping wll handle getting rid of the last element.*/
	stackHolder.push(entry); /*Add new to holder*/
	/*while(!stackTemp->empty()){
		stackHolder->push(stackTemp->front());
		stackTemp->pop();
	}*/

	/*NOTE:::: THe following is for deleting.*/
	/*If stacks next first is == last, then just remove that position...? Iterate till you get to second to last, pop that off, then move everything back into q1?...We also have size >1 because we can access the size of it. */
}

template<class Item>
void stack<Item>::pop(){
	/*Let's make sure we aren't empty.*/
	assert(!stackHolder.empty());
	/*Move everything but last element.*/
	while(stackHolder.size()!=1){/*NOTE check size is up to 1 because want to return last one.*/
		stackTemp.push(stackHolder.front());
		stackHolder.pop();
	}
	/*Get rid of last item*/
	stackHolder.pop();
	/*Put everything back into the queue that holds the stack.*/
	while(!stackTemp.empty()){
		stackHolder.push(stackTemp.front());
		stackTemp.pop();
	}
}

template<class Item>
void stack<Item>::print(){
	/*Call queues print function.*/
	stackHolder.print();
}





#endif
