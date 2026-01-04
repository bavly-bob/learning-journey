/*
leetcode problem link: https://leetcode.com/problems/reverse-integer/
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x
causes the value to go outside the signed 32-bit integer range [-2**31, 2**31 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/
#include <climits>
class Solution {
public:
    int reverse(int x) 
    {
        int result = 0;
        do
        {
            if (result > INT_MAX/10 || (result == INT_MAX/10 && x % 10 > 7)) return 0;
            if (result < INT_MIN/10 || (result == INT_MIN/10 && x % 10 < -8)) return 0;
            result = result*10 + x %10;
        }while( x /= 10);
        return result; 
    }

};