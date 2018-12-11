// FILE: btClass.h
// TEMPLATE CLASS PROVIDED: binaryTree<Item> (a binary tree where each node has
//   an item) The template parameter, Item, is the data type of the items in the
//   tree's nodes. It may be any of the C++ built-in types (int, char, etc.),
//   or a class with a default constructor, a copy constructor and an assignment
//   operator.
//
// NOTE: Each non-empty tree always has a "current node."  The location of
// the current node is controlled by three member functions: shiftUp,
// shiftToRoot, shiftLeft, and shiftRight.
//
// CONSTRUCTOR for the binaryTree<Item> template class:
//   binaryTree( )  
//     Postcondition: The binary tree has been initialized as an empty tree
//     (with no nodes).
//
// MODIFICATION MEMBER FUNCTIONS for the binaryTree<Item> template class:
//   void createFirstNode(const Item& entry)
//     Precondition: size( ) is zero.
//     Postcondition: The tree now has one node (a root node), containing the
//     specified entry. This new root node is the "current node."
//
//   void shiftToRoot( )
//     Precondition: size( ) > 0.
//     Postcondition: The "current node" is now the root of the tree.
//
//   void shiftUp( )
//     Precondition: hasParent( ) returns true.
//     Postcondition: The "current node" has been shifted up to the parent of
//     the old current node.
//
//   void shiftLeft( )
//     Precondition: hasLeft( ) returns true.
//     Postcondition: The "current node" been shifted down to the left child
//     of the original current node.
//
//   void shiftRight( )
//     Precondition: hasRight( ) returns true.
//     Postcondition: The "current node" been shifted down to the right child
//     of the original current node.
//
//   void change(const Item& new_entry)
//     Precondition: size( ) > 0.
//     Postcondition: The data at the "current node" has been changed to the
//     new entry.
//
//   void addLeft(const Item& entry)
//     Precondition: size( ) > 0, and hasLeft( ) returns false.
//     Postcondition: A left child has been added to the "current node,"
//     with the given entry.
//
//   void addRight(const Item& entry)
//     Precondition: size( ) > 0, and hasRight( ) returns false.
//     Postcondition: A right child has been added to the "current node,"
//     with the given entry.
//
// CONSTANT MEMBER FUNCTIONS for the binaryTree<Item> template class:
//   size_t size( ) const
//     Postcondition: The return value is the number of nodes in the tree.
//
//   Item retrieve( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the data from the "current node."
//
//   bool hasParent( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a parent.
//
//   bool hasLeft( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a left child.
//
//   bool hasRight( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a right child.
//
// VALUE SEMANTICS for the binaryTree<Item> template class:
//   Assignments and the copy constructor may be used with binaryTree objects.
//
// DYNAMIC MEMORY USAGE by the binaryTree<Item> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   createFirstNode, addLeft, addRight, the copy constructor, and the 
//   assignment operator.

#ifndef __BT_CLASS_H__
#define __BT_CLASS_H__


#include <cstdlib>    // Provides size_t
#include "Sefa_B_HW5_Q1.h"   // Provides btNode<Item> template class
#include <stack> //include stack datastructure that will be used for parent.



using namespace std;

template <class Item>
class binaryTree
{
public:
    // CONSTRUCTORS and DESTRUCTOR
    binaryTree( );
    binaryTree(const binaryTree& source);
    ~binaryTree( );
    // MODIFICATION MEMBER FUNCTIONS
    void createFirstNode(const Item& entry);
    void shiftToRoot( );
    void shiftUp( );
    void shiftLeft( );
    void shiftRight( );
    void change(const Item& new_entry);
    void addLeft(const Item& entry);
    void addRight(const Item& entry);
    // CONSTANT MEMBER FUNCTIONS
    size_t size( ) const;
    Item retrieve( ) const;
	btNode<Item>* retrieveNode(); /* retrieve pointer to currentNode.*/
    bool hasParent( ) const;
    bool hasLeft( ) const;
    bool hasRight( ) const;
	void print(); /*Function I added just to test that everything is okay.*/ 
	void setRoot(btNode<Item>* new_root); /*This is a function that is needed for Q4 for transplant. Tree may need to set its root to a tree.*/

private:
    // TODO
	btNode<Item> * currentNode;
	btNode<Item> * rootNode;
	stack<Item> * shiftingRoute;
	size_t count;
	/*NOTE == Textbook says to use a count variable to keep track of number of nodes... I can either incorperate this and just addjust it in createNode and addLeft/Right, or I can just continue to use numNodes => Note this would take N time...*/



	/*btNode<Item> * parentNode;*/
	/*NOTE my intial thoughts are we 
	 * have one node that maintains the current, 
	 * and one parent node. We can easily get the children 
	 * nodes using currentNode and btNode's functions left and right. 
	 * 
	 * Another thought. Parent can actually just be the root. 
	 * And I would iterate till child is the current. 
	 * Though that kind of is hard because do I iterate left or right? 
	 * It would be a matter of going through.
	 * Unless its already in order, than I can just compare data. 
	 * 
	 * Get back to this thought of parent/root==> 
	 * for now naming root and setting to NULL
	 * Going to actually include a parent node too.... For now. 
	 * Another thought that just occured is maybe each parent 
	 * will hold a node to its parent? Like backwards linking? Idk tbh. 
	 *
	 * */

	/* NOTE according to Timmy we only need rootNode and currentNode. 
	 * Just use rootNode to iteratre to the parent node, 
	 * or the node before the child. 
	 * This to me is just a bit confusing because its redundant recursiveness. 
	 * Like having to go through. But timmy said the challenge of holding parent 
	 * is that youll have to keep track of multiple pointers, 
	 * and its harder that way.
	 *
	 * */
};

#include "Sefa_B_HW5_Q2.copy.cpp" // TODO
#endif 
