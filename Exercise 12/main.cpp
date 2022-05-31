#include <iostream>
#include <vector>
#include <string>
#include "Exercise12.h"
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {

 vector<string> words = { "dog","cat","apt","sue","bob","dam","and","ape","sum","dim"};

  radixsort(words, 3);

  for(int i=0; i<words.size(); i++)
  {
    cout << words[i] << endl;
  }

  /*vector<vector<string>> buckets(26); // buckets for radixsort
  buckets[0].push_back("dog");

  for(int i=0; i<buckets[0].size(); i++)
  {
    cout << buckets[0][i] << endl;
  }
  
  buckets[0].push_back("cat");

  for(int i=0; i<buckets[0].size(); i++)
  {
    cout << buckets[0][i] << endl;
  }*/

  /*string word = "dog";
  int n = word[2]-97;
  cout << n << endl;*/

}