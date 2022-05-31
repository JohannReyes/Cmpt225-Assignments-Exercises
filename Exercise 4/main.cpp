#include "Deque.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
  
  //original dq
  Deque dq;
  dq.insert_back(1);
  dq.insert_back(2);
  dq.insert_back(3);
  dq.insert_back(4);
  dq.insert_back(5);
  cout << "OG dq with size " << dq.size() << ": ";
  dq.printForwards();
  cout << endl;

  //copy constructor test
  Deque cp(dq);
  cout << endl << "CC with size " << cp.size() << ": ";
  cp.printForwards();
  cout << endl;

  //check with editing 
  dq.insert_back(6);
  cp.insert_back(7);
  cout << endl << "OG dq with size " << dq.size() << ": ";
  dq.printForwards();
  cout << endl;
  cout << endl << "CC with size " << cp.size() << ": ";
  cp.printForwards();
  cout << endl;
  

  //overloaded assignment test
  Deque ot = dq;
  cout << endl;
  cout << "OA with size " << ot.size() << ": ";
  ot.printForwards();
  cout << endl;

  //check with editing 
  dq.insert_back(7);
  ot.insert_back(8);
  cout << endl << "OG dq whith size " << dq.size() << ": ";
  dq.printForwards();
  cout << endl;
  cout << endl << "OA with size " << ot.size() << ": ";
  ot.printForwards();
  cout << endl;
}