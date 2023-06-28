#include "Sequence.h"
#include <cassert>
#include <iostream>

/*
* Sangeet Satpathy
* Assignment 9P
* CS2B
* Sequence.cpp
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


Private Data members:
headPtr: a pointer to the first node of the list
tailPtr: a pointer to the last node of the list
numItems: the number of items in the list
cursor: a pointer to the current item in the list
precursor: a pointer to the previous item (before the current item).
*/


namespace cs_sequence {
	Sequence::Sequence() {
		numItems = size_type();
		headPtr = nullptr;
		tailPtr = nullptr;
		cursor = nullptr;
		precursor = nullptr;
	}







	void Sequence::insert(const value_type& entry) {

		Node* new_node = new Node;
		new_node->data = entry;
		numItems++;

		if (cursor == headPtr || cursor == nullptr) { // insert at front (or into empty list).
			new_node->next = headPtr;                 // precursor remains nullptr.
			headPtr = new_node;
			if (numItems == 1) {
				tailPtr = new_node;
			}
		}
		else {                                       // inserting anywhere else
			new_node->next = cursor;                   // tailPtr, headPtr and precursor don't change.
			precursor->next = new_node;
		}

		cursor = new_node;
	}








	void Sequence::start() {
		cursor = headPtr;
		precursor = nullptr;
	}










	void Sequence::advance() {
		assert(is_item());
		cursor = cursor->next;
		if (precursor == nullptr) {
			precursor = headPtr;
		}
		else {
			precursor = precursor->next;
		}
	}










	size_type Sequence::size() const {
		return numItems;
	}









	bool Sequence::is_item() const {
		if (cursor == nullptr) {
			return false;
		}
		return true;
	}








	value_type Sequence::current() const {
		assert(is_item());
		return cursor->data;
	}






	//inserts after the current item; if there is no item, then attach to the end of the sequence
	// if NULL
	void Sequence::attach(const value_type& entry) {
		Node* new_node = new Node;
		new_node->data = entry;
		new_node->next = nullptr;
		numItems++;


		if (numItems == 1) { //the list is empty
			headPtr = new_node;
			tailPtr = new_node;
			cursor = new_node;
			precursor = nullptr;
		}
		//if we are at the END of a list.
		else if (cursor == tailPtr || cursor == nullptr) {  
			if (cursor != nullptr) {
				cursor->next = new_node;
				precursor = cursor;
			}
			else {
				tailPtr->next = new_node;
			}
			tailPtr = new_node;
			
			cursor = new_node;
		}
		else { // attaching a node in a non-empty, not end case list.
			new_node->next = cursor->next;
			cursor->next = new_node;
			cursor = cursor->next;

			if (precursor == nullptr) {
				precursor = headPtr;
			}
			else {
				precursor = precursor->next; 
			}
		}
	}







	void Sequence::remove_current() {
		assert(is_item());
		if (numItems == 1) {
			headPtr = nullptr;
			cursor = nullptr;
			precursor = nullptr;
			tailPtr = nullptr;
		}
		else if (cursor == headPtr) { //if we are removing the first node
			headPtr = cursor->next;
			cursor = cursor->next;
			precursor = nullptr;
		}
		else { 
			cursor = cursor->next; //even if it's the last item, then the cursor is now nullptr;
			precursor->next = cursor; //the precursor's next point now points to the updated cursor
			if (cursor == nullptr) {
				tailPtr = precursor;
			}
		}
		numItems--;
	}



	



	Sequence::~Sequence() {
		clear(headPtr);
	}






	///Recursively clears the linked list
	void Sequence::clear(Node* currNode) {
		if (currNode == nullptr) {
			return;
		}
		clear(currNode->next);
		delete currNode;

	}






	Sequence::Sequence(const Sequence& rhs) {
		copy(rhs);
	}








	void Sequence::copy(const Sequence& rhs) {
		if (this == &rhs) {
			return;
		}

		Node* iter = rhs.headPtr;
		headPtr = nullptr;
		tailPtr = nullptr;
		cursor = nullptr;
		precursor = nullptr; 
		numItems = size_type();
		while (iter != nullptr) {
			Node* newNode = new Node;
			newNode->data = iter->data;
			newNode->next = nullptr;
			if (headPtr == nullptr) {
				headPtr = newNode;
				tailPtr = newNode;
			}
			else {
				tailPtr->next = newNode;
				tailPtr = newNode;
			}

			if (rhs.cursor == iter) {
				cursor = newNode;
			}
			else if (rhs.precursor == iter) {
				precursor = newNode;
			}

			iter = iter->next;
		}
		numItems = rhs.numItems;
	}







	Sequence Sequence::operator=(const Sequence& rhs) {
		copy(rhs);
		return *this;
	}
}