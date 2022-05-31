#include <iostream>
#include <string>
#include "Exercise6.h"
using std::cout;
using std::endl;
using std::string;

int main() {
  
  string arr[7] = {"a","c","e","f","b","g","d"};

  cout << "Unsorted: ";
  for(int i=0; i<7; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl << endl;

  int counter = quicksort<string>(arr, 7);
  cout << "Sorted: ";
  for(int i=0; i<7; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl << "# of partition calls: " << counter << endl;
  
}