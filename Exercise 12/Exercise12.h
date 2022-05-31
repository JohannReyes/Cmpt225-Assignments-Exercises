#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

void radixsort(vector<string> & words, int len){

  while(len > 0)
  {
    vector<vector<string>> buckets(26); // buckets for all 26 letters
  
    for(int i=0; i<words.size(); i++) // put all words into respective buckets
    { // use the letter itself as an index to input into buckets
      buckets[words[i][len-1]-97].push_back(words[i]);
    }

    words.clear(); // clear words vector for inserting new order of words
    for(int i=0; i<buckets.size(); i++) // insert new order of words using buckets
    {
      for(int j=0; j<buckets[i].size(); j++)
      {
        words.push_back(buckets[i][j]); // re-insert into words from buckets
      }
    }
    buckets.clear();  // reset buckets for next pass
   
    len-=1;  // decrement len to go to next letter
  }
}