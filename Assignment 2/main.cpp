#include <iostream>
#include <string>
#include "QueueT.h"
using std::cout;
using std::endl;
using std::string;

int main() {

  QueueT<string> q1;
  q1.enqueue("b");
	q1.enqueue("d");
	q1.enqueue("f");

  cout << "empty: 0 = " << q1.empty() << endl;
	cout << "print: {b,d,f} = ";
	q1.print();
	cout << endl << "size: 3 = " << q1.size() << endl;

  QueueT<string> q2(q1);
	QueueT<string> q3;
	q3 = q1;
 
	string n = q1.dequeue();
  cout << "q1 dequeued b = " << n << endl;
 
	cout << "q1 post copy: {d,f} = ";
	q1.print();
  q2.dequeue();
  q2.dequeue();
	cout << endl << "q2 (copy): {f} = ";
	q2.print();
  q3.enqueue("h");
	cout << endl << "q3 (op=): {b,d,f,h} = ";
	q3.print();

  QueueT<string> q4;
	q4.enqueue("e");
  cout << endl << "print: {e} = ";
	q4.print();
 
	QueueT<string> q5(q1.merge(q4));
	cout << endl << "q5 (merge): {d,e,f} = ";
	q5.print();

  q1.concatenate(q4, 1);
	cout << endl << "q1 (concatenate): {d,f,e} = ";
	q1.print();
  cout << endl << "size: 3 = " << q1.size() << endl;

  cout << endl << "size: 0 = " << q4.size() << endl;

  NodeT<string>* front = q1.getFront();
	cout << endl << "front->next->data: f = " << front->next->data << endl;

  //concatenate test making param empty
  /*QueueT<int> q6;
  q6.enqueue(7);
	q6.enqueue(8);
	q6.enqueue(9);
  cout << endl << "q6: {7,8,9} = ";
	q6.print();
  cout << endl << "size: 3 = " << q6.size() << endl;

  q1.concatenate(q6, 3);
	cout << endl << "q1 (concatenate): {4,6,5,7,8,9} = ";
	q1.print();
  cout << endl << "size: 6 = " << q1.size() << endl;
  cout << endl << "q6: {} = ";
	q6.print();
  cout << endl << "size: 0 = " << q6.size() << endl;*/
  

  //double test with empty lists
  /*QueueT<int> q7;
  cout << endl << "size: 0 = " << q7.size() << endl;
  cout << endl << "q7: {} = ";
	q7.print();*/

  //merge test where one is empty and other is not
  /*QueueT<int> q14(q7.merge(q1));
  cout << endl << "q14 (merge): {4,6,5} = ";
	q14.print();
  cout << endl << "size: 3 = " << q14.size() << endl;*/

  //concatenate test into an empty list
  /*q7.concatenate(q1, 3);
  cout << endl << "q7 (concatenate): {4,6,5} = ";
	q7.print();
  cout << endl << "size: 3 = " << q7.size() << endl;*/

  // merge test where one queue is bigger than the other
  /*QueueT<int> q8;
  q8.enqueue(1);
	q8.enqueue(3);
  QueueT<int> q9;
  q9.enqueue(2);
	q9.enqueue(4);
  q9.enqueue(5);
	q9.enqueue(6);
  QueueT<int> q10(q8.merge(q9));
	cout << endl << "q10 (merge): {1,2,3,4,5,6} = ";
	q10.print();
  cout << endl << "size: 6 = " << q10.size() << endl;*/

  //merge test where both queues are empty
  /*QueueT<int> q11;
  QueueT<int> q12;
  QueueT<int> q13(q11.merge(q12));
  cout << endl << "q13 (merge): {} = ";
	q13.print();
  cout << endl << "size: 0 = " << q13.size() << endl;*/

  //copy and overloaded with empty queues
  /*QueueT<int> q15;
  QueueT<int> q16(q15);
  QueueT<int> q17;
  q17 = q15;
  cout << endl << "q16 (copy): {} = ";
	q16.print();
	cout << endl << "q17 (op=): {} = ";
	q17.print();*/
}