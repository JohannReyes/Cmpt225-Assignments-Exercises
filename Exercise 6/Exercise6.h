#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <class T>
int partition(T arr[], int low, int high){

  T pivot = arr[high];
  int pivot_index = high;
  while(low < high)
  {
    if(arr[low] > pivot)  // if value is to be moved
    {
      high-=1;  // decrement high for comparison
      while(pivot < arr[high] && low < high)
      {
        high-=1;  //finds a value to swap with
      }
      if(low < high)  // to ensure no extra swaps
      {
        T temp = arr[high];
        arr[high] = arr[low]; // swaps two values
        arr[low] = temp;
      }
    }
    low+=1; //increments low, walking though arr
  }

  arr[pivot_index] = arr[high]; // swaps pivot with middle
  arr[high] = pivot;  //puts pivot into middle
  return high; // returns the middle pivot index
}

template <class T>
void qs(T arr[], int low, int high, int &counter){

   if (low < high)
   {
      int pivot = partition(arr, low, high);
      counter+=1; // increment counter for every part call
      qs(arr, low, pivot-1, counter);
      qs(arr, pivot+1, high, counter);
   }
}

template <class T>
int quicksort(T arr[], int n){

  int counter = 0;  // variable to count partition
  qs(arr, 0, n-1, counter);
  return counter; 
}