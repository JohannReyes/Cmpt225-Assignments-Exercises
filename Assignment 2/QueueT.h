#pragma once
#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::runtime_error;

template <class T>  // template class
class NodeT
{
public:
  T data;
	NodeT* next;
	NodeT(T val, NodeT* nxt) : data(val), next(nxt) {};
	NodeT(T val) : data(val), next(nullptr) {};
};

template <class T>  // template class
class QueueT
{
public:
  QueueT(); // constructor 

  QueueT(const QueueT & qt);  //copy constructor 

  //overloaded operator
	QueueT & operator=(const QueueT & qt); 

	~QueueT();  // destructor 

  void enqueue(T val); // inserter (at front)

  T dequeue();  // deleter  (at back)

  void print() const; // print fcn

  bool empty() const; //empty or not fcn

  int size() const; // returns current list size

  // concatenate fcn
  void concatenate(QueueT & qt, int n);

  //merge fcn
  QueueT merge(const QueueT & qt) const;

  // for accessing list directly 
  NodeT<T>* getFront();

private:
  int sz;
	NodeT<T>* front;
	NodeT<T>* back;
  // helper fcn for copy const/overloaded op
  void copyQueueT(const QueueT & qt);
  // destructor helper fcn
  void removeAll();
};
/*---------------------------------------------------------------------*/
// QueueT implementations

// constructor 
template <class T>  // template class
QueueT<T>::QueueT(){

  sz = 0;
  front = back = nullptr;
}

// helper fcn for copy const/overloaded op
template <class T>  // template class
void QueueT<T>::copyQueueT(const QueueT & qt){

  sz = qt.sz;
  if(qt.front == nullptr) //checks if empty
  {
    front = back = nullptr;
  }
  else
  {
    front = new NodeT<T>(qt.front->data);  //copies front
    NodeT<T>* copytemp = front;  //temp node for copy list
    NodeT<T>* origtemp = qt.front; //temp node for OG list
    for(int i=1; i<sz; i++) //loops through list copying each node
    {
      copytemp->next = new NodeT<T>(origtemp->next->data);
      copytemp = copytemp->next;
      origtemp = origtemp->next;
    }
    back = copytemp; //once outside loop, sets back as last node
  }
}

// copy constructor
template <class T>  // template class
QueueT<T>::QueueT(const QueueT & qt){

  copyQueueT(qt); //calls helper for copying
}

//overloaded operator
template <class T>  // template class
QueueT<T> & QueueT<T>::operator=(const QueueT & qt){

  if (this != &qt) 
  {
		removeAll();
		copyQueueT(qt); //calls helper for copying
	}
	return *this;
}

//destructor helper fcn
template <class T>  // template class
void QueueT<T>::removeAll(){

  NodeT<T>* temp = front;
	while (front != nullptr) // walks through list, deleting every node
  {
		front = temp->next;
		delete temp;
		temp = front;
	}
	sz = 0;
	front = back = nullptr;
}

// destructor 
template <class T>  // template class
QueueT<T>::~QueueT(){
  
  removeAll();
}

// inserts val at back
template <class T>  // template class
void QueueT<T>::enqueue(T val){

	if (back == nullptr) // checks if Queue is empty
  {
		back = new NodeT<T>(val);  //makes front = back (since only 1 item)
		front = back;
	}
  else
  {
    back->next = new NodeT<T>(val);
    back = back->next;
  }
  sz+=1;
}

// deletes current front
template <class T>  // template class
T QueueT<T>::dequeue(){

  if (front == nullptr) // checks if Queue is empty
  {
		throw runtime_error("dequeue failed - empty");
	}
  
  T dq_data = front->data;  //saves data of front
  NodeT<T>* temp = front;  //temp node to delete
  front = front->next;  //make second node new front
  if(front == nullptr)  //if queue is now empty
  {
    back = nullptr; //make back null as well
  }
  sz-=1;
  delete temp;
  return dq_data;
}

//print fcn; front to back
template <class T>  // template class
void QueueT<T>::print() const{

  NodeT<T>* temp = front;
  cout << "{";
  while(temp != nullptr)
  {
    cout << temp->data;
    if(temp->next != nullptr)
    {
      cout << ",";
    }
    temp = temp->next;
  }
  cout << "}" << endl;
}

// checks if queue is empty
template <class T>  // template class
bool QueueT<T>::empty() const{

  if(front == nullptr)  //if empty
  {
    return true;
  }
  return false;
}

// returns current queue size
template <class T>  // template class
int QueueT<T>::size() const{

  return sz;
}

// concatenate fcn
template <class T>  // template class
void QueueT<T>::concatenate(QueueT & qt, int n){

  if(n>qt.sz) //checks n is greater that actual queue size
  {
    throw runtime_error("concatenate failed - n > param sz");
  }
  
  for(int i=0; i<n; i++)
  {
    if(front == nullptr) //if "this" is empty
    {
      front = back = qt.front;  //sets front and back
    }
    else
    {
      back->next = qt.front;  // adds "qt" to "this" at back
      back = back->next;      // changes back
    }
    sz+=1;
    qt.front = qt.front->next;  //changes qt.front to new qt.front
    qt.sz-=1;
  }
  back->next = nullptr; //makes sure back->next is null
  // this also makes sure that the concatenated node is removed from qt
}

//merge fcn (start with "this" then "qt" alternating)
template <class T>  // template class
QueueT<T> QueueT<T>::merge(const QueueT & qt) const{

  QueueT qt_merge;
  NodeT<T>* objtemp = front; // temp for "this"
  NodeT<T>* partemp = qt.front;  // temp for qt
  while(objtemp != nullptr|| partemp != nullptr)
  {
    if(objtemp != nullptr)  //insert "this" data
    {
      qt_merge.enqueue(objtemp->data);
      objtemp = objtemp->next;
    }
    if(partemp != nullptr)  //insert "qt" data
    {
      qt_merge.enqueue(partemp->data);
      partemp = partemp->next;
    }
  }
  return qt_merge;
}

//returns front node direclty 
template <class T>  // template class
NodeT<T>* QueueT<T>::getFront(){

  return front;
}