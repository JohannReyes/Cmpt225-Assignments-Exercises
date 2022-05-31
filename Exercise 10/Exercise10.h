#pragma once
#include <iostream>

bool isMinHeap(int arr[], int size){

  for(int i=0; i<size; i++)
  {
    if( (2*i)+1 >= size && (2*i)+2 >= size )  // if leaf node
    {
      break;  // no need to further check leaf nodes so break loop
    }
    if( (2*i)+1 < size && arr[i] > arr[(2*i)+1] ) // if left child index is valid and parent > left child
    {
      return false; // return false since parent > child which is false in min heap
    }
    if( (2*i)+2 < size && arr[i] > arr[(2*i)+2] ) // if right child index is valid and parent > right child
    {
      return false; // return false since parent > child which is false in min heap
    }
  }

  return true;  // if every node is valid for min heap, then return true
}