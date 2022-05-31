#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

class HashTable
{
public:
  // Constructors
  HashTable();
  HashTable(int num);
  ~HashTable();
  HashTable(const HashTable & hashT);
  HashTable & operator=(const HashTable & hashT);

  // Mutators
  void insert(string str);

  // Accessors
  bool find(string str) const;
  int size() const;
  int maxSize() const;
  double loadFactor() const;
  //double PrimeCheck() const; // TEST FCN
  //void print() const; // Test FCN

private:
  string* arr;
  int arrSize;  // underlying arr size
  int currSize; // current amount of items in arr
  int PrimeNum; // h2 value
  void copyHashTable(const HashTable & hashT); // helper function for deep copy
  bool isPrime(int num); // helper fcn to determine if num is prime or not
  int Hashing1(string str) const; // 1st/Main Hashing Function
  int Hashing2(string str) const; // 2nd Hashing Function
  void newHashTable(); // helper fcn for creating a bigger HT when loadF > 0.67
};