#include "StringSet.h"
#include <iostream>
#include <string>
#include <stdexcept>
using std::out_of_range;
using std::cout;
using std::endl;
using std::string;

int main() {

  // StringSet class test

  StringSet ss1;
  ss1.insert("cat");
  ss1.insert("bat");
	int findIndex = ss1.find("bat");
  cout << "index foung at: " << findIndex << endl;
	cout << "ss1 size = " << ss1.size() << endl;
  ss1.insert("rat");
  ss1.insert("badger");
  findIndex = ss1.find("dog");
  cout << "index foung at: " << findIndex << endl;
	cout << "ss1 size = " << ss1.size() << endl;
  cout << "ss1 ";
  ss1.print();
  ss1.remove("cat");
  ss1.remove("rat");
  cout << "ss1 size = " << ss1.size() << endl;
  cout << "ss1 ";
  ss1.print();

  /*StringSet ss1;
	ss1.insert("cat");
  ss1.insert("bat");
	int findIndex = ss1.find("bat");
  cout << findIndex << endl;
	cout << "ss1 size = " << ss1.size() << endl;
  ss1.insert("rat");
  ss1.insert("badger");
  cout << "ss1 ";
  ss1.print();
  
  StringSet ss2;
  ss2.insert("elephant");
  ss2.insert("bat");
  ss2.insert("hamster");
  cout << "ss2 ";
  ss2.print();

  //union test using copy constructor 
  StringSet ss3(ss1.unions(ss1));
  cout << "ss3 unions CC ";
  ss3.print();

  //union test using overloaded assignment
  StringSet ss4;
  ss4 = ss1.unions(ss2);
  cout << "ss4 unions OA ";
  ss4.print();

  //intersection test using copy constructor
  StringSet ss5(ss2.intersection(ss1));
  cout << "ss5 intersection CC ";
  ss5.print();

  //intersection test using overloaded assignment
  StringSet ss6;
  ss6 = ss2.intersection(ss1);
  cout << "ss6 intersection OA ";
  ss6.print();

  //difference test using copy constructor
  StringSet ss7(ss2.difference(ss1));
  cout << "ss7 difference CC ";
  ss7.print();

  //difference test using overloaded assignment
  StringSet ss8;
  ss8 = ss2.difference(ss1);
  cout << "ss8 difference OA ";
  ss8.print();

  cout << "Done and Compiled!" << endl;*/
}