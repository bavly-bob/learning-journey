/*
https://leetcode.com/problems/binary-number-with-alternating-bits/description/

given an integer, return true if it is a binary number with alternating bits
*/
class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        bool prev = n % 2;
        n >>= 1;

        while (n)
        {
            bool curr = n % 2;

            if (curr == prev)
                return false;

            prev = curr;
            n >>= 1;
        }
        return true;
    }
};