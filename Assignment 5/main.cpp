#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "spellcheck.h"
using std::ifstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
  
  /*HashTable ht(2);
  ht.insert("cat");
  ht.insert("dog");
  ht.insert("frog");
  ht.insert("bat");
  ht.insert("rat");

  cout << endl << "Original" << endl;
  ht.print();
  cout << "# of items: " << ht.size() << endl;
  cout << "Size of arr: " << ht.maxSize() << endl;
  cout << "Prime #: " << ht.PrimeCheck() << endl;
  //cout << ht.find("cat") << endl; // 1
  //cout << ht.find("god") << endl; // 0

  HashTable ht2(ht);
  ht2.insert("fish");
  cout << endl << "Copy Constructor" << endl;
  ht2.print();
  cout << "# of items: " << ht2.size() << endl;
  cout << "Size of arr: " << ht2.maxSize() << endl;
  cout << "Prime #: " << ht2.PrimeCheck() << endl;

  HashTable ht3;
  ht3 = ht;
  ht3.insert("lizard");
  cout << endl << "Overloaded Assignment" << endl;
  ht3.print();
  cout << "# of items: " << ht3.size() << endl;
  cout << "Size of arr: " << ht3.maxSize() << endl;
  cout << "Prime #: " << ht3.PrimeCheck() << endl;*/

  HashTable ht;
  string name;
  ifstream myfile ("wordlist1000.txt");
  if (myfile.is_open())
  {
    while (myfile >> name)
    {
      ht.insert(name);
    }
    myfile.close();
  }
  else 
  {
    cout << "Failed to open file" << endl; 
  }
  cout << "# of items: " << ht.size() << endl;
  cout << "Size of arr: " << ht.maxSize() << endl;
  //cout << "Prime #: " << ht.PrimeCheck() << endl << endl;

  vector<string> vec = missingLetter(ht, "ca");
  cout << endl << "Vector:" << endl;
  for(int i=0; i<vec.size(); i++)
  {
    cout << vec[i] << endl;
  }

}