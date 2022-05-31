#include <iostream>
#include "Exercise10.h"
using std::cout;
using std::endl;

int main() {
  
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};

  if(isMinHeap(arr, 10))
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }
}