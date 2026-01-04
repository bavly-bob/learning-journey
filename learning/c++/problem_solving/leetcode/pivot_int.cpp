/*
leetcode problem link: https://leetcode.com/problems/find-the-pivot-integer/
Given a positive integer n, find the pivot integer x such that:
The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. 
If no such integer exists, return -1. 
It is guaranteed that there will be at most one pivot index for the given input.
*/
#include <cmath>
class Solution 
{
public:
    int pivotInteger(int n) 
    {
        int help = (n*(n+1))/2;
        return (sqrt(help) == (int) sqrt(help))? sqrt(help): -1;
    }
};

// alitte safer 

/*
long long help = (long long)n * (n + 1) / 2;
long long x = (long long)sqrt(help);
return (x * x == help) ? x : -1;
*/