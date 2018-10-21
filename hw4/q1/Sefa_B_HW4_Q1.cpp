#ifndef __STACK_CPP__
#define __STACK_CPP__

#include "Sefa_B_HW4_Q1.h"

/*
 * What: This function deletes or frees up space allocated by the stack.
 * How: This function utalizes C++ function to remove elements and free upspace via the delete operator.
 * Precondition: N/A
 * Postcondition: The memory that this stack allocated is now freed, and all other varaibles are reset to 0. 
 * Worst Time Complexity: O(n) because data is an array. 
 *
 * */

template<class Item>
stack<Item>::~stack(){
	delete [] data;
	used = 0; /*Reset all other data, even though it wont matter, but it just clears space.*/
	capacity = 0; 
}

/*
 * What: This function inserts a new item into the top of the stack. 
 * How: This function first checks to see if the stack has enough space to insert more items. If it does not, it allocates a larger stack and transfers all its current items into the new stack (Maintaining the order); it deletes the old stack to free up space. Then, it adds the new item to the end of the array (or top of the stack), and it increases the variable that keeps track of its size by 1.  
 * Precondition: entry must be of type item. 
 * Postcondition: The stack now has a new element, entry, at the top. 
 * Worst Time Complexity: O(n) because of larger array allocation.  
 * 
 * */
template<class Item>
void stack<Item>::push(const Item& entry){
	/*Check if we have enough space*/
	if(used>=size()){
		Item * larger = new Item[++capacity];
		for(size_t i = 0; i < used; i++){
			larger[i] = data[i];
		}
		delete [] data;
		data = larger;
	}
	data[used++]=entry;
}

/*
 * What: This function checks to see if the stack is empty.
 * How: This function compares the number of items in the array to 0, and returns true if so, or false if not. 
 * Precondition: N/A
 * Postcondition: Returns if the stack has no items in it or not.  
 * Worst Time Complexity: O(1)
 *
 * */
template<class Item>
bool stack<Item>::isEmpty() const{
	return used == 0;
}


/*
 * What: This function removes the last item from the stack.
 * How: This function first checks to see if the stack is empty, and halts the program if it is true. Then, it just decreases the value of used, as then the stack wouldn't be able to see the previous last element (the invariant of the class).
 * Precondition: The stack must not be empty. 
 * Postcondition: The top element of the stack is now removed.  
 * Worst Time Complexity: O(1) 
 */
template<class Item>
void stack<Item>::pop(){
	assert(!isEmpty());
	used--;
}


/*
 * What: This function prints out the items in the array (Not in stack order). Used only for testing. 
 * How: This function loops through each element and prints out the item. 
 * Precondition: N/A
 * Postcondition: Each item of the dynamic array is printed. 
 * Worst Time Complexity: O(n)
 * */
/*NOTE this is kind of not the right way of printing for a stack since its supposed to go backwards, but you get the point.*/
template<class Item>
void stack<Item>::print() const{
	for(size_t i = 0; i < used; i++){
		cout << data[i] << endl;
	}
}


/*
 * What: This function creates a new stack that is the copy of another.
 * How: This function copies over all the data from source stack into the current stack. 
 * Precondition: N/A
 * Postcondition: A new stack is created that is a copy of the source stack.  
 * Worst Time Complexity: O(n)
 * 
 * */
template<class Item>
stack<Item>::stack(const stack<Item>& source){
	/*NOTE no need to check if they are the same because stacks are not the same*/
	capacity = source.capacity;
	used = source.used;
	data = new Item[capacity];
	for(size_t i = 0; i < used; i++){
		data[i] = source.data[i];
	}
}

/*
 * What: This function deletes or frees up space allocated by the stack.
 * How: This function first checks to see if the stack in the argument is nt the same as the one calling the function, if so do nothing because the stacks are the same. If not the case, then free up the space from the current stack, and copy over all elements from source into current stack (including used and capacity). 
 * Precondition: N/A
 * Postcondition: The current stack is now a copy of source stack.  
 * Worst Time Complexity: O(n). 
 *  
 * */

template<class Item>
void stack<Item>::operator =(const stack<Item>& source){
	/*Check to see if source is the same thing, like y = y*/
	if(this == &source){ /*This is saying, if the address of current pointer, is same as the address of the argument. */
		return; /*Dont do anything if both of their addresses are the same.*/
	}
	used = source.used;
	capacity = source.capacity;
	delete [] data; /*Free up any allocated space. */ 
	data = new Item[capacity];
	for(size_t i = 0; i < used; i++){
		data[i] = source.data[i];
	}
}


/*
 * What: This function returns the top item in the stack.
 * How: This funtion first checks to see if the stack is empty or not. If the case is that its empty, it halts the program. If not, then it returns the item that is at the top of the stack.
 * Precondition: Stack must contain items. 
 * Postcondition: The top item of the stack is returned. 
 * Worst Time Complexity: O(1)
 *
 */
template<class Item>
Item stack<Item>::top() const{
	assert(!isEmpty());
	return data[used-1]; /*Just return the last one in the list.*/
}

/*
 *  * What: This function swaps the content of two stacks.
 *   * How: This function first checks to see if the two stacks are the same. If the case is true nothing happens. If it is not the case, then a temportary stack is created using the copy construcor, being a copy of stack1. Then, stack1 is assigned by stack2, follwoing stack2 is assigned by stack1. 
 * Precondition: N/A
 * Postcondition: The two stacks, stack1 and stack2, are swapped. 
 * Worst Time Complexity: O(n)
 * 
 * */
template<class Item>
void swapStacks(stack<Item>& stack1, stack<Item>& stack2){
	if(&stack1 == &stack2) /*If the two stacks are the same, dont do anything*/
		return;
	stack<Item> s1Temp(stack1);/*else, create a temp stack of one of them*/
	stack1 = stack2; /*Assign one stack to the other*/
	stack2 = s1Temp; /*Assign stack two to temp.*/
}


/*
 * What: This function returns the size of the stack.
 * How: This funtion returns the variable used, which is the variable that keeps track of the number of items in the stack. 
 * Precondition: N/A 
 * Postcondition: The size of the stack is returned. 
 * Worst Time Complexity: O(1)
 */
template<class Item>
size_t stack<Item>::size() const{
	return used; /*Just return the last one in the list.*/
}





/*template<class Item>
void stack<Item>::swapStacks(stack& secondStack){
	this = secondStack;
}*/

#endif
