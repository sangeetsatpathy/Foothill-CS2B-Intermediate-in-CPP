#pragma once

/*
* Sangeet Satpathy
* Assignment 9P
* CS2B
* Sequence.h
* 
The Sequence class is built using the Linked List concept and supports its own iterator.

Sequence(): postcondition: The Sequence has been initialized to an empty Sequence.
void start():    postcondition: The first item in the Sequence becomes the current item (but if the 
			Sequence is empty, then there is no current item).
void advance():
	// precondition: is_item() returns true
	// Postcondition: If the current item was already the last item in the Sequence, then there 
	// is no longer any current item. Otherwise, the new current item is the item immediately after 
	// the original current item.
void insert(const value_type& entry):
	// Postcondition: A new copy of entry has been inserted in the Sequence before the 
	// current item. If there was no current item, then the new entry has been inserted at the 
	// front. In either case, the new item is now the current item of the Sequence.

value_type size() const:
	// Postcondition: Returns the number of items in the Sequence.

bool is_item() const:
	// Postcondition: A true return value indicates that there is a valid "current" item that
	// may be retrieved by the current member function (listed below). A false return value
	// indicates that there is no valid current item.

value_type current() const:
	// Precondition: is_item() returns true
	// Postcondition: The current item in the Sequence is returned.
void attach(const value_type& entry);
	// Postcondition: A new copy of entry has been inserted in the Sequence after the current
	// item. If there was no current item, then the new entry has been attached to the end of
	// the Sequence. In either case, the new item is now the current item of the Sequence.

void remove_current();
	// Precondition: is_item returns true.
	// Postcondition: The current item has been removed from the Sequence.  If the item removed
	// was the last item in the Sequence, then there is now no current item.  Otherwise, the item
	// that was after the removed item is now the current item.
*/
namespace cs_sequence {
	typedef int value_type;

	typedef int size_type;

	class Sequence {
	public:
		class Node {
		public:
			value_type data;
			Node* next;
		};
		Sequence();
		void start();
		void advance();
		void insert(const value_type& entry);
		size_type size() const;
		bool is_item() const;
		value_type current() const;
		void attach(const value_type& entry);
		void remove_current();
		~Sequence();
		Sequence operator=(const Sequence& rhs);
		Sequence(const Sequence& rhs);
	private:
		size_type numItems;
		Node* headPtr;
		Node* tailPtr;
		Node* cursor;
		Node* precursor;
		void clear(Node* currNode);
		void copy(const Sequence& rhs);
	};
}