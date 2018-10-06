#ifndef __NODE_H__
#define __NODE_H__

#include <cstdlib>
using namespace std;

class node{
	public:
		typedef int nodeDataType;
		void set_link(node* ptr){ link_field = ptr;}
		nodeDataType data() const{return data_field; }
		node* link(){ retunr link_field; }
		const node* link(){ return link_field; } /*NOTE this function is constant because a constant pointer can call it, where it doesn't want to change any of its values in the future. */
		node(const nodeDataType& init_data = nodeDataType(), 
				node* init_link = NULL){
			link_field = init_data;
			data_field = init_data;
		}
		void set_data(const nodeDataType& dat){ data_field = dat;}
	private:
		node * link_field;
		nodeDataType data_field;
};
	
	void list_clear(node*& head_ptr); /* NOTE *&   tells us that we want to be able to change the location of head_ptr, ie what it points to. */

