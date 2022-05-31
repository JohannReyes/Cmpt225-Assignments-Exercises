#pragma once
#include <string>
using std::string;

class StringSet 
{
public:

    //constructor
    StringSet(); 

    //destructor 
    ~StringSet();

    //copy constructor (makes a deep copy)
    StringSet(const StringSet & strset);

    //overloaded assignment operator
    StringSet & operator=(const StringSet & strset);

    //inserting a string, returning a bool
    bool insert(string st);

    //removes a string
    void remove(string st);

    //returns the size of the string
    int size() const;

    //finds a string and returns a num
    int find(string st) const;

    // returns a union of two StringSet 
    StringSet unions(const StringSet & strset) const;

    // returns the intersection of two StringSet 
    StringSet intersection(const StringSet & strset) const;

    // returns the difference of two StringSet 
    StringSet difference(const StringSet & strset) const;
    
    //prints the arr of strings (testing fcn for programmer)
    void print() const;

private:

  string* arr;
  int curr_sz;
  int max_sz;
  void copyStringSet(const StringSet & strset); // copy/overld helper fcn
};