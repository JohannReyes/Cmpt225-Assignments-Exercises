#include <iostream>
#include "List.h"
using std::cout;
using std::endl;
using std::vector;

int main() {

  List list;
  cout << "List before:" << endl;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(3);
  list.insert(3);
  list.insert(2);
  list.insert(1);
  list.insert(4);
  list.print();

  cout << "List after:" << endl;
  int n = list.remove(2);
  list.print();
  cout << n << " item(s) removed" << endl;

  cout << "Code Executed" << endl;
}