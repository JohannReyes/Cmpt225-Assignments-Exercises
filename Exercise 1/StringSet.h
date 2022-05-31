#pragma once
#include <string>
using std::string;
class StringSet 
{
public:

    //constructor
    StringSet();

    //inserting a string, returning a bool
    bool insert(string st);

    //removes a string
    void remove(string st);

    //returns the size of the string
    int size();

    //finds a string and returns a num
    int find(string st);

};