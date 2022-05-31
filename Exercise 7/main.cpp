#include <iostream>
using std::cout;
using std::endl;
#include "BST.h"
	
// Driver code
int main()
{
	BST root;
  root.insert(4);
  root.insert(2);
  root.insert(6);
  root.insert(1);
  root.insert(3);
  root.insert(5);
  root.insert(7);

  root.print();
	
	cout << "Height of tree is " << root.height() << endl;
	return 0;
}