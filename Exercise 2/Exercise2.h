#pragma once
using std::cout;
using std::endl;

int remove(int arr[], int &n, int num){

  int counter=0;
  for(int i=0; i<n; i++)  // running though array
  {
    //cout << "main loop run" << endl;
    if(arr[i] == num) // checking for a match
    {
      while(arr[i] == num && i != n)  // checking after move
      {
        counter+=1;
        n-=1;
        //cout << i << " " << n << endl;
        for(int i2=i; i2<n; i2++) // move everything one down
        {
          arr[i2] = arr[i2+1];
        }
      }
    }
  }
  return counter;
}
