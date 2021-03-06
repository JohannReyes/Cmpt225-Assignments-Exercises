#include "List.h"
#include <iostream>

using std::cout;
using std::endl;

// To be completed for exercise 3
// ONLY CHANGE BODY OF THIS METHOD
int List::remove(int val)
{
	int counter=0;
  Ex3Node* prev = nullptr;
  Ex3Node* current = head;

  while(current != nullptr)
  {
    if(current->data == val)
    {
      Ex3Node* temp = current;
      current = current->next;
      prev->next = current;
      delete temp;
      counter+=1;
    }
    else
    {
      prev = current;
      current = current->next;
    }
  }
  
	return counter;
}

// Constructors and destructor
// Creates an empty list
List::List()
{
	head = nullptr;
}

List::~List()
{
	deleteList();
}
// Copy constructor and overloaded assignment operator not implemented

// Mutators------------------
// PARAM: val = value to be inserted
// POST: inserts val at the front of the list
void List::insert(int val)
{
	Ex3Node* newNode = new Ex3Node(val, head);
	head = newNode;
}

// int remove - see top of file

// Helper method for destructor
// (and un-implemented overloaded assignment operator)
void List::deleteList()
{
	Ex3Node* temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// Accessors
bool List::check(const vector<int> & v) const
{
	Ex3Node* p = head;
	for (int x : v) {
		if (p == nullptr || p->data != x) {
			return false;
		}
		p = p->next;
	}

	return (p == nullptr); // p != nullptr list contains unchecked values
}

// Prints the contents of the list starting from head
void List::print() const
{
	Ex3Node*p = head;
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
}
