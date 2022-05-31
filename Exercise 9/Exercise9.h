#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
using std::vector;
using std::map;
using std::pair;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

map<string, double> readGradeFile(string fname){

  map<string, double> gradefile;
  string name;
  double grade;
  ifstream myfile (fname);
  if (myfile.is_open())
  {
    while (myfile >> name >> grade)
    {
      gradefile.insert(pair<string, double>(name, grade));
    }
    myfile.close();
  }
  else 
  {
    cout << "Failed to open file" << endl; 
  }
  
  return gradefile;
}

vector<double> getGrades(const map<string, double> & gradeMap, string start, string end){

  vector<double> grades;
  map<string,double>::const_iterator itr;
  itr = gradeMap.lower_bound(start);
  while( itr != gradeMap.lower_bound(end) ) 
  {
    grades.push_back(itr->second);
    itr++;
  }
  
  return grades;
}