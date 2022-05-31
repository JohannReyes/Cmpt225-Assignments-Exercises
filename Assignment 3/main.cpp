#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

// Q1
// PARAM: arr is array to print the Cartesian product of, n is size of arr
int cartesianProduct(int arr[], int n)
{
  int i = 0;
  int ops = 1;  // initialize for int i
  while (i < n) 
  {
    int j = 0;
    ops+=2; // while,int j
    while (j < n) 
    {
      cout << "{" << arr[i] << "," << arr[j] << "}";
      j++;  
      cout << " ";
      ops+=4; //while,cout,j++,cout
    }

    cout << endl;
    i++;
    ops+=3; //while terminate,cout,i++
  }
  ops+=1; //while terminate
  return ops;
}

// Q2
int triangle(int x)
{
  int i = 0;
  int ops = 1; //initialize, int i
  while (i < x) 
  {
    int j = 0;
    ops+=2; //while, int j
    while (j <= i) 
    {
      cout << j << " ";
      j++;
      ops+=3; //while,cout,j++
    }

    cout << endl;
    i++;
    ops+=3; //while terminate,cout,i++
  }
  ops+=1; //while terminate

  while (i > 0) 
  {
    i--;
    int j = 0;
    ops+=3; //while, i--,int j
    while (j <= i) 
    {
      cout << j << " ";
      j++;
      ops+=3; //while,cout,j++
    }

    cout << endl;
    ops+=2; //while terminate, cout
  }
  ops+=1; //while terminate
  return ops;
}

// Q3
// PARAM: arr is array from which duplicates are to be removed, n is size of arr
vector<int> removeDuplicates(int arr[], int n, int & ops)
{
  vector<int> result;
  int i = 0;
  ops+=2;  // initialize:int result,int i
  while (i < n) 
  {
    int iResult = 0;
    bool duplicate = false;
    ops+=3; //while,int iResult,bool duplicate

    while (iResult < (int)result.size() && !duplicate) 
    { //note 4
      if (arr[i] == result[iResult]) 
      {
        duplicate = true;
        ops+=1; //duplicate
      }

      iResult++;
      ops+=3; //while,if,iResult++
    }
    ops+=1; //while terminate

    if (!duplicate) 
    {
      result.push_back(arr[i]); //note 4
      ops+=1; //push_back
    }

    i++;
    ops+=2; //if,i++
  }
  ops+=1; //while terminate
  return result;
}

// Q4 (helper)
// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
  return r * columns + c;
}

//Q4 (main)
// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows, int & ops)
{
  // Create result array
  int columns = rows;
  int* result = new int[rows * columns];
  int r = 0;
  ops = 3; //initialize: int colm, int* res, int r

  while (r < rows) 
  {
    int c = 0;
    ops+=2; //while,int c
    while (c < columns) 
    { //columns = rows
      int next = 0;
      int iNext = 0;
      ops+=3; //while,int next, int iNext

      while (iNext < rows) 
      {
        next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];
        iNext++;
        ops+=3; //while,next+=,iNext++
      }

      result[rcIndex(r, c, columns)] = next;
      c++;
      ops+=3; //while terminate,result=,c++
    }

    r++;
    ops+=2; //while terminate,r++
  }
  ops+=1; //while terminate
  return result;
}

// Q5
// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
int ssort(int arr[], int n, int i)
{
  int ops = 0;  //initialize
  if (i < n-1) 
  {
    // Find and swap smallest remaining
    int next = i + 1;
    int smallest = i;
    ops+=2; //int next,int smallest

    while (next < n) 
    {
      if (arr[next] < arr[smallest]) 
      {
        smallest = next;
        ops+=1; //smallest=
      }
      next++;
      ops+=3; //while,if,nex++
    }

    // Swap i with smallest
    int temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;
    ops+=4; //while terminate,int temp,arr[i]=,arr[smallest]=
    cout << ops << endl;
    ops = ops + ssort(arr, n, i + 1); // add ops from recursive call
  }
  ops+=1; //if
  return ops;
}

// Q6
// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
int pattern(int n, int i)
{
  int ops = 0;
  if (n > 0) 
  {
    ops = ops + pattern(n/2, i);
    // Print i spaces
    cout << string(i, ' '); // NOTE: counts as ONE operation

    // A loop to print n asterisks, each one followed by a space
    int ast = 0;
    ops+=2; //cout,int ast
    while (ast < n) 
    {
      cout << "* ";
      ast++;
      ops+=3; //while,cout,ast++
    }

    cout << endl;
    i += n;
    ops+=3; //while terminate,cout,i+=
    ops = ops + pattern(n / 2, i);
  }
  ops+=1; //if
  return ops;
}

int main() {
  
  int ops = pattern(16, 0);
  cout << ops << endl;
}