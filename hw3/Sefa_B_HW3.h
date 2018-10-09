#ifndef __NODE_H__
#define __NODE_H__

#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

class node{
	public:
		typedef int nodeDataType;
		void set_link(node* ptr){ link_field = ptr;}
		nodeDataType data() const{return data_field; }
		node* link(){ return link_field; }
		const node* link() const{ return link_field; } /*NOTE this function is constant because a constant pointer can call it, where it doesn't want to change any of its values in the future. */
		node(const nodeDataType& init_data = nodeDataType(), 
				node* init_link = NULL){
			link_field = init_link;
			data_field = init_data;
		}
		void set_data(const nodeDataType& new_data){ data_field = new_data;}
	private:
		node* link_field;
		nodeDataType data_field;
};
	
	void list_clear(node*& head_ptr); /* NOTE *&   tells us that we want to be able to change the location of head_ptr, ie what it points to. */
	void list_head_insert(node*& head_ptr, const node::nodeDataType& data);
	void list_insert(node* previous_ptr, const node::nodeDataType& data);
	void list_end_insert(node *& head_ptr, const node::nodeDataType& entry);
	void list_ith_insert(node *& head_ptr, const node::nodeDataType& entry, const size_t& pos);
	size_t list_length(const node* head_ptr);
	void list_remove(node* previous_ptr);
	void list_head_remove(node*& head_ptr);
	void list_end_remove(node*& head_ptr);
	void list_ith_remove(node* head_ptr, const size_t& i);
	void list_copy(const node* source_ptr, node *& head_ptr, node *& tail_ptr);
	//const nodeDataType (const node*)
	node * list_locate(node* head_ptr, const size_t& position);
	const node* list_locate(const node* head_ptr, const std::size_t& position);
	node * list_search(node* head_ptr, const node::nodeDataType& entry);
	const node * list_search(const node* head_ptr, const node::nodeDataType& entry);
	void list_tail_remove(node* ptr); /*NOT sure which pointer would be entered here.*/
	void list_print(const node* head_ptr);
	bool list_cycle(const node* head_ptr);
	void list_swap_next(node* i_ptr, const std::size_t& i);
	void list_swap_IJ(node * ptr, const std::size_t& i, const std::size_t& j);
	void list_reverse(node* head_ptr);

#endif

