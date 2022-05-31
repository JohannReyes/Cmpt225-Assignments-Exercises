#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include "Exercise9.h"
using std::vector;
using std::map;
using std::pair;
using std::string;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::cout;
using std::endl;

int main() {
  /*ofstream myfile ("list.txt");
  if (myfile.is_open())
  {
    myfile << "kate 78.513\n";
    myfile << "bob 23.45\n";
    myfile << "sue 87.456\n";
    myfile << "kurt 80.45\n";
    myfile << "morgan 61.43\n";
    myfile.close();
  }
  else cout << "Unable to open file";*/

  map<string, double> gradefile = readGradeFile("list.txt");
  map<string,double>::iterator itr;
  itr = gradefile.begin();
  while( itr != gradefile.end() ) 
  {
    cout << itr->first << " " << itr->second << endl;
    itr++;
  }

  vector<double> grades = getGrades(gradefile, "b", "s");
  vector<double>::iterator it;
  it = grades.begin();
  while (it != grades.end()) 
  {
	  cout << *it << endl;
	  it++;
  }

  return 0;
}