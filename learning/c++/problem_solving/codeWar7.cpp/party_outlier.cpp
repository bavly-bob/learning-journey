// https://www.codewars.com/kata/5526fc09a1bbd946250002dc/train/cpp
// Find The Parity Outlier
// You are given an array (which will have a length of at least 3,
// but could be very large) containing integers. The array is either

#include <iostream>
#include <vector>
using namespace std;

int FindOutlier(vector<int> arr)
{
    int even =0, odd =0;
    for(int i = 0; i < 3; i++)
    {
      if( (arr[i]%2) == 0) even ++;
      else odd++;
    }

    if(even <= 1)
    {
      for(int i : arr)
        if((i%2) == 0) return i;
    }
    else
    {
      for(int i : arr)
        if((abs(i)%2) == 1) return i; 
    }

    return 0;
}