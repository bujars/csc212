#ifndef __QUEUE_CPP__
#define __QUEUE_CPP__

#include "Sefa_B_HW4_Q4.h"

/*NOTE all functions of stack need -> because they need to point to their own version of that function.*/



template<class Item>
queue<Item>::queue(size_t init_cap){
	queueHolder = stack<Item>(init_cap);
	queueTemp = stack<Item>(init_cap);
}

template<class Item>
queue<Item>::~queue(){
	/*According to stack overflow question 677653 --> Just having this title will call stacks deconstructor and everything will be deleted. You just need to have it. See example of class C using class A (in this case queue calling stack.). */
	/*queueHolder.~stack();
	queueTemp.~stack();*/
}

template<class Item>
void queue<Item>::pop(){
	/*NOTE stack's verion of pop also checks assertion, but can just do it here.*/
	assert(!empty());
	/*Since stack was ordered to be in reverse, or in a way the queue would be ordered, to remove first, just remove top!*/
	queueHolder.pop();
}
//#if 0

/*NOTE queueHOLDER holds the queue in the way it should, meaning that using pop/top gives it its order.*/

template<class Item>
void queue<Item>::push(const Item& entry){
	/*Move everything from stack 1 into stack to so that order remains same*/
	while(!(queueHolder.isEmpty())){
		queueTemp.push(queueHolder.top());
		queueHolder.pop();
	}
	/*Add new entry to top of stack (where everything is reversed)*/
	queueTemp.push(entry);
	/*Re-reverse everything from stack 2 into stack 1 so that order is back.*/
	while(!queueTemp.isEmpty()){
		queueHolder.push(queueTemp.top());
		queueTemp.pop();
	}

}

template<class Item>
size_t queue<Item>::size() const{
	return queueHolder.size();
}

template<class Item>
void queue<Item>::print(){
	cout << "STACK WAY:" << endl;
	queueHolder.print();
	cout << endl << endl << "QUEUE WAY" << endl;
	while(!queueHolder.isEmpty()){
		cout << queueHolder.top() << endl;
		queueTemp.push(queueHolder.top());
		queueHolder.pop();
	}
	/*Put everything back.*/
	while(!queueTemp.isEmpty()){
		/*cout << queueHolder.top() << endl;*/
		queueHolder.push(queueTemp.top());
		queueTemp.pop();
	}
}

template<class Item>
Item queue<Item>::front() const {
	assert(!queueHolder.isEmpty());
	return queueHolder.top();
}

template<class Item>
bool queue<Item>::empty() const {
	return queueHolder.isEmpty();
}

//#if 0

template<class Item>
void queue<Item>::operator=(const queue<Item>& source){
	if(this == &source){
		return;
	}
	//cout << queueHolder->top() << endl;

	//delete queueHolder;
	//queueHolder.~stack();
	
	/*Since these are stacks, it will use the stack assignment operator!*/
	
	queueHolder=source.queueHolder;
	//delete queueTemp;
	//queueTemp.~stack();
	queueTemp = source.queueTemp;
}


//#if 0
template<class Item>
queue<Item>::queue(const queue<Item>& source){
	queueHolder = stack<Item>(source.queueHolder);
	queueTemp = stack<Item>(source.queueTemp);
} 
//#endif 
//#endif
#endif
