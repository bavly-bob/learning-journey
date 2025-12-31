// Delete occurrences of an element if it occurs more than n times
// https://www.codewars.com/kata/554ca54ffa7d91b236000023
// Given a list and a number, create a new list that contains each number of
// the list at most n times without reordering.
// For example if the input number is 2, and the input list is
// [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] since
// this would lead to 1 and 2 being in the result 3 times, and
// then take [3], which leads to [1,2,3,1,2,3].

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> deleteNth(vector<int> arr, int n)
{
  unordered_map<int,int> tmp;
  vector<int> result;
  for(int i = 0; i<arr.size(); i++){
    tmp[arr[i]] ++; // count how many times number appear
    if(tmp[arr[i]] <= n) // check if he still can see the photo or not
      result.push_back(arr[i]);
  }
  
  
  return result;
}