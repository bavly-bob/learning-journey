// https://www.codewars.com/kata/59f11118a5e129e591000134/train/cpp
// Sum of single array elements
// The task is to write a function that returns the sum of all
// the integers that appear only once in an array.

#include <iostream>
#include <vector>
using namespace std;

int repeats(vector<int>v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++) 
    {
        for(int j = i; j < v.size(); j++) 
        {
            if(v[i] == v[j] && i != j) 
            {
                v[j] = 0;
                v[i] = 0;
            }
        }
    }
    for(int i = 0; i < v.size(); i++) 
    {
        sum += v[i];
    }
    return sum;
}