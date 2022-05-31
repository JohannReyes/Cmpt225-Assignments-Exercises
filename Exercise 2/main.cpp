#include <iostream>
#include "Exercise2.h"
using std::cout;
using std::endl;

int main() {

  int arr[] = {1,1,1,1,1,1,1,1}, n = 8;

  int x = remove(arr, n, 2);
  if(n==0)
  {
    cout << "arr: empty";
  }
  else 
  {
    cout << "arr: ";
    for(int i=0; i<n; i++)
    {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
  cout << x <<" item(s) removed" << endl;
  cout << "arr now contains " << n << " items" << endl;


}