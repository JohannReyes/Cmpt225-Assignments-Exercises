#include "StringSet.h"
#include <iostream>
#include <string>
#include <stdexcept>
using std::out_of_range;
using std::cout;
using std::endl;
using std::string;

// Implementation of each class methods

//constructor
StringSet::StringSet(){
  
  max_sz = 2;
  curr_sz = 0;
  arr = new string[max_sz];
}

//destructor
StringSet::~StringSet(){

  delete[] arr; //deallocates memeory
  curr_sz = 0;  //resets current size to 0
}

// helper fucntion for copy constructor and overloaded operator 
void StringSet::copyStringSet(const StringSet & strset){

  curr_sz = strset.curr_sz; //copies contents of strset
  max_sz = strset.max_sz;
  arr = new string[curr_sz];  // makes a new arr = to strset arr
  for(int i=0; i<curr_sz; i++)  //copies the contents of the arr
  {
    arr[i] = strset.arr[i];
  }
}

//copy constructor (makes a deep copy)
StringSet::StringSet(const StringSet & strset){

  copyStringSet(strset);  //calls helper fcn to make the deep copy
}

//overloaded assignment operator
StringSet & StringSet::operator=(const StringSet & strset){

  if(this != &strset) //checks if object is copying itself
  {
    delete[] arr;   // must first deallocate memory of object
    copyStringSet(strset);  //makes the deep copy with helper fcn
  }

  return *this;   // return the object after deep copy
}


//inserting a string, returning a bool
bool StringSet::insert(string st){

  if(find(st) != -1)  //checking if string already exists using find fcn
  {
    return false; //means that string already exists, so return false
  }

  //check if curr == max, if so need to make a new array with larger size
  if(curr_sz == max_sz)
  {
    max_sz = max_sz * 2;  //doubles maximum size
    string* newarr;
    newarr = new string[max_sz];  //makes new array with new max size
    for(int i=0; i<curr_sz; i++)
    {
      newarr[i] = arr[i]; // copies all contents from old to new
    }
    delete[] arr;   // deletes old arr to ensure no memory leak
    arr = newarr;   // assigns newarr to StringSet's arr pointer
  }
  arr[curr_sz] = st;  //insert string into last index
  curr_sz+=1;         //increment curr sz by +1
  return true;
}

//removes a string
void StringSet::remove(string st){

  if(curr_sz == 0)  //checking first if arr is empty
  {
    throw out_of_range("arr is empty"); //throw out_of_range if empty
  }

  for(int i=0; i<curr_sz; i++)  //running though arr
  {
    if(arr[i] == st)  //checking for match
    {
      arr[i] = arr[curr_sz-1];  //replacing match with last string
      curr_sz-=1;             //decrement current size by -1
      break;
    }
  }
}

//returns the size of the string
int StringSet::size() const{

  return curr_sz;
}

//finds a string and returns a num
int StringSet::find(string st) const{

  for(int i=0; i<curr_sz; i++)  //running through arr
  {
    if(arr[i] == st)  // checking if match found
    {
      return i;
    }
  }

  return -1;
}

// returns a union of two StringSet 
StringSet StringSet::unions(const StringSet & strset) const{

  StringSet union_set;
  for(int i=0; i<curr_sz; i++) //insert all strings from "this" arr 
  {
    union_set.insert(arr[i]);
  }

  for(int i=0; i<strset.curr_sz; i++) //insert all strings from "strset" arr
  {
    union_set.insert(strset.arr[i]);
  }
  
  return union_set;
}

// returns the intersection of two StringSet 
StringSet StringSet::intersection(const StringSet & strset) const{

  StringSet intr_set;
  for(int i=0; i<curr_sz; i++)  //runs through arr of "this"
  {
    //this calls strset's find using strings from "this" arr
    /*this checks if a string in "this" is also in "strset" and
     if so, it means it is an intersection and must be inserted into
     intr_set*/
    if(strset.find(arr[i]) != -1) //cheking for a match in both arrs
    {
      intr_set.insert(arr[i]); //if match, insert into intr_set
    }
  }

  return intr_set;
}

// returns the difference of two StringSet (this - strset)
StringSet StringSet::difference(const StringSet & strset) const{

  StringSet diff_set;
  for(int i=0; i<curr_sz; i++)
  {
     //this calls strset's find using strings from "this" arr
     /*this checks if a string in "this" is also in "strset" and
     if so, must subtract it form diff_set or in this case 
     simply not inserting it*/
    if(strset.find(arr[i]) == -1)//checks if there is no match
    {
      diff_set.insert(arr[i]);//if no match, insert the string
    }
  }

  return diff_set;
}

//prints arr of strings
void StringSet::print() const{

  cout << "Arr: ";
  for(int i=0; i<curr_sz; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}