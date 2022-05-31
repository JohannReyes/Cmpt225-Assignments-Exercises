#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "HashTable.h"
using std::vector;
using std::string;
using std::sort;
using std::swap;
using std::cout;
using std::endl;

/*----------------Implementation of all spellcheck functions----------------*/

// returns all strings in dict that can be made by deleting a single letter from word
vector<string> extraLetter(const HashTable & dict, string word){

  vector<string> vec;

  if(dict.find(word) == true) 
  {
    vec.push_back(word); // if word is found, insert alone
  }
  else
  { // generate all possible strings for extraLetter
    string extraWord; // string to be searched/inserted
    for(int i=0; i<word.length(); i++) // removes each char
    {
      extraWord =  word; // reset extraWod for next char delete
      extraWord.erase(i, 1); // the new word with a deleted char
      if(dict.find(extraWord) == true)
      {
        vec.push_back(extraWord); // if extraWord is found, insert
      }
    }
  }

  sort(vec.begin(), vec.end()); // sorts vec before returning
  return vec;
}

// returns all strings in dict that can be made swapping any two adjacent letters in word
vector<string> transposition(const HashTable & dict, string word){

  vector<string> vec;

  if(dict.find(word) == true)
  {
    vec.push_back(word); // if word is found, insert alone
  }
  else
  { // generate all possible strings for transposition
    string transWord;
    for(int i=0; i<word.length()-1; i++) // swaps each adjacent letters
    {
      transWord = word; // resets transWord for next swap
      swap(transWord[i], transWord[i+1]); // swap
      if(dict.find(transWord) == true)
      {
        vec.push_back(transWord); // if transWord is found, insert
      }
    }
  }

  sort(vec.begin(), vec.end()); // sorts vec before returning
  return vec;
}

// returns all pairs of strings in dict that can be made by inserting a single space in word
vector<string> missingSpace(const HashTable & dict, string word){

  vector<string> vec;

  if(dict.find(word) == true)
  {
    vec.push_back(word); // if word is found, insert alone
  }
  else
  { // generate all possible strings for missingSpace
    string spaceWord;  // the word to be inserted into vec if found
    string str1, str2; // the two pairs to look for
    for(int i=1; i<word.length(); i++) // seperat word on each char
    {
      str1 = word.substr(0, i); // creat substring 1 and 2
      str2 = word.substr(i);
      if(dict.find(str1) == true && dict.find(str2) == true)
      { // if both substrs are found, combine and insert
        spaceWord = str1 + " " + str2; // combine substrs with a space
        vec.push_back(spaceWord); // insert spaceWord
      }
    }
  }

  sort(vec.begin(), vec.end()); // sorts vec before returning
  return vec;
}

// helper search fcn for missingLetter, prevents duplicates
bool find(vector<string> & vec, int size, string word)
{
  for(int i=0; i<size; i++)
  {
    if(vec[i] == word)
    {
      return true;
    }
  }
  return false;
}
// returns all strings in dict that can be made by inserting any single letter of the alphabet at any position in word
vector<string> missingLetter(const HashTable & dict, string word){

  vector<string> vec;

  if(dict.find(word) == true)
  {
    vec.push_back(word); // if word is found, insert alone
  }
  else
  { // generate all possible strings for missingLetter
    string missWord = word; // string to be searched/inserted
    for(int i=0; i<word.length()+1; i++) 
    { // inserts all letters into all positions of word
      for(int j=97; j<123; j++) // runs through all 26 letters
      {
        string letter;
        letter+=char(j);  // converts j into char for insert
        missWord.insert(i, letter); // insert letter into missWord
        if(find(vec, vec.size(), missWord) == false) // checks if word is already in vec
        { // if not in vec, then procced with search/insert
          if(dict.find(missWord) == true)
          { 
            vec.push_back(missWord); // if found, insert missWord
          }
        }
        missWord.erase(i,1); // reset missWord for next char insert
      }
    }
  }

  sort(vec.begin(), vec.end()); // sorts vec before returning
  return vec;
}

// returns all strings in dict  that can be made by changing any single letter of word
vector<string> incorrectLetter(const HashTable & dict, string word){

  vector<string> vec;

  if(dict.find(word) == true)
  {
    vec.push_back(word); // if word is found, insert alone
  }
  else
  { // generate all possible strings for incorrectLetter
    string incWord;
    for(int i=0; i<word.length(); i++)
    {
      incWord = word; // resets incWord for next letter change
      for(int j=97; j<123; j++) // runs through all 26 letters
      {
        incWord[i] = j;
        if(incWord != word) // prevents from checking same word multiple times
        {
          if(dict.find(incWord) == true)
          {
            vec.push_back(incWord); // if incWord is found, insert
          }
        }
      }
    }
  }

  sort(vec.begin(), vec.end()); // sorts vec before returning
  return vec;
}