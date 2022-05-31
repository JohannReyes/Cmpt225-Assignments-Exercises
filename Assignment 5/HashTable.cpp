#include <iostream>
#include <vector>
#include <string>
#include "HashTable.h"
using std::vector;
using std::string;
using std::cout;
using std::endl;

/*----------------Implementation of each class methods----------------*/

// Default Constructor
HashTable::HashTable(){

  arrSize = 101;
  arr = new string[arrSize];
  currSize = 0;
  PrimeNum = 53; // first prime number greater than 101/2 = 50.5
}

// isPrime helper fcn to determine if num param is prime or not
bool HashTable::isPrime(int num){

  if (num == 0 || num == 1) // 0 and 1 are not prime numbers
  {
    return false;
  }
  else 
  {
    for (int i = 2; i <= num / 2; ++i) 
    {
      if (num % i == 0) 
      {
        return false;
      }
    }
  }

  return true;
}
// Constructor
HashTable::HashTable(int num){

  arrSize = 2 * num;
  while(isPrime(arrSize) == false)  
  {
    arrSize+=1; // increment arrSize until it is prime
  }
  arr = new string[arrSize];
  currSize = 0;
  PrimeNum = arrSize/2 + 1;
  while(isPrime(PrimeNum) == false)  
  {
    PrimeNum+=1; // increment PrimeNum until it is prime
  }
}

//Destructor
HashTable::~HashTable(){

  delete[] arr; //deallocates memeory
  arrSize = 0;  //resets all other data
  currSize = 0;
  PrimeNum = 0;
}

// Helper function for Copy Constructor/Overloaded Assignment
void HashTable::copyHashTable(const HashTable & hashT){

  arrSize = hashT.arrSize;
  currSize = hashT.currSize;
  PrimeNum = hashT.PrimeNum;
  arr = new string[arrSize]; // copies all data from hashT

  for(int i=0; i<arrSize; i++)  
  {
    arr[i] = hashT.arr[i];  // copies all contents from hashT
  }
}
// Copy Constructor
HashTable::HashTable(const HashTable & hashT){

  copyHashTable(hashT);  //makes the deep copy with helper fcn
}
// Overloaded Assignment Operator
HashTable & HashTable::operator=(const HashTable & hashT){

  if(this != &hashT) //checks if object is copying itself
  {
    delete[] arr;   // must first deallocate memory of object
    copyHashTable(hashT);  //makes the deep copy with helper fcn
  }

  return *this;   // return the object after deep copy
}

// 1st/Main Hashing Function
int HashTable::Hashing1(string str) const{
  
  int stringValue = str[0]-96; // initialize stringVlaue with 1st char
  int i=1;  // string char index, starts at 2nd char
  while(str[i] != '\0') // run through string and use Horner's method to calc
  {
    stringValue = ( (stringValue*32) + (str[i]-96) )%arrSize;
    i++; // increment index to run through all chars of str
  }
  return stringValue;
}
// 2nd Hashing Function
int HashTable::Hashing2(string str) const{

  int modVal = str[0]-96; // initialize stringVlaue with 1st char
  int i=1;  // string char index, starts at 2nd char
  while(str[i] != '\0') // run through string and use Horner's method to calc
  {
    modVal = ( (modVal*32) + (str[i]-96) )%PrimeNum;
    i++;
  }
  return PrimeNum - modVal;
}
// helper fcn for creating new HT when loadFactor > 0.67
void HashTable::newHashTable(){

  int oldArrSize = arrSize; // record old arrSize
  arrSize = (arrSize * 2) + 1; // update arrSize 
  while(isPrime(arrSize) == false) // find first prime number > 2*new arrSize
  {
    arrSize+=1; 
  }
  string* newArr = new string[arrSize]; // make a newArr with new arrSize
  for(int i=0; i<oldArrSize; i++)  // find all strings from old arr 
  {
    if(arr[i] != "")  // if arr contains a string, rehash into newArr
    { // makes sure that all strings form arr are inserted correctly in newArr
      int index = Hashing1(arr[i]);
      int doubleHash = Hashing2(arr[i]);
      while(newArr[index] != "")
      {
        index+=doubleHash;  // if collision, increment by doublehash
        if(index >= arrSize)
        {
          index-=arrSize; // if it reaches the end, wrap around to start
        }
      }
      newArr[index] = arr[i]; // insert string into newArr with rehashing
    }
  }
  
  PrimeNum = arrSize/2 + 1; // update PrimeNum with updated arrSize
  while(isPrime(PrimeNum) == false)  
  {
    PrimeNum+=1; // increment PrimeNum until it is prime
  } // finished updating PrimeNum

  arr = newArr; // make the newArr the original arr, updating arr
}
// Insert new string
void HashTable::insert(string str){

  if(find(str) == false) // if str does not exist in HashTable, insert
  {
    int index = Hashing1(str);  // initialize index and doublehash increment
    int doubleHash = Hashing2(str);
    
    while(arr[index] != "")
    {
      index+=doubleHash;  // if collision, increment by doublehash
      if(index >= arrSize)
      {
        index-=arrSize; // if it reaches the end, wrap around to start
      }
    }

    arr[index] = str; // inserts string
    currSize+=1; // update currSize
  }

  if(loadFactor() > 0.67) // if loadFactor exceeds 0.67, create new bigger HT
  {
    newHashTable(); // helper fcn for creating new HT
  }
}
// Search for string in HashTable
bool HashTable::find(string str) const{

  int index = Hashing1(str);  // initialize index and doublehash increment
  int doubleHash = Hashing2(str);
  while(arr[index] != "")
  {
    if(arr[index] == str)
    {
      return true;
    }
    index+=doubleHash;  // if not found, increment by doublehash
    if(index >= arrSize)
    {
      index-=arrSize; // if it reaches the end, wrap around to start
    }
  }
  // if it runs through entire loop without returning, then must be false
  return false;
}

// Returns amount of items in HashTable
int HashTable::size() const{

  return currSize;
}

// Returns size of underlying array
int HashTable::maxSize() const{

  return arrSize;
}

// Returns current loadFactor
double HashTable::loadFactor() const{

  double dblcurrSize = currSize;
  double dblarrSize = arrSize;
  return dblcurrSize/dblarrSize;
}

/*// TEST FCN
double HashTable::PrimeCheck() const{

  return PrimeNum;
}
// TEST FCN
void HashTable::print() const{

  for(int i=0; i<arrSize; i++)
  {
    cout << i << ": " << arr[i] << endl;
  }
}*/