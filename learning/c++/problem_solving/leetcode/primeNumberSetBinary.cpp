/*
https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

Given two integers left and right, return the count of numbers in the range [left, right] that have an even number of set bits in their binary representation.

Example 1:
Input: left = 6, right = 10
Output: 4
Explanation: In binary, the numbers in the range are:
6: 110 (2 set bits)
7: 111 (3 set bits)
8: 1000 (1 set bit)
9: 1001 (2 set bits)
10: 1010 (2 set bits)
Out of these, 6, 9, and 10 have an even number of set bits.

Example 2:
Input: left = 8, right = 10
Output: 1
Explanation: In binary, the numbers in the range are:
8: 1000 (1 set bit)
9: 1001 (2 set bits)
10: 1010 (2 set bits)
Out of these, 9 and 10 have an even number of set bits.
*/

// first solution came to my mind "brute force" but it's not efficient as the constraints are small
// the constraints are left <= right <= 10^6
// and the time complexity is O((right - left) * sqrt(right))
// which is too slow
class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (long long i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    int setBits(int x)
    {
        int count = 0;
        do
        {
            if(x % 2 == 1) count ++; 
        }while(x >>= 1);
        return count;
    }
    
    int countPrimeSetBits(int left, int right) 
    {
        int count =0;
        for(int i = left ; i <= right; i++)
            if(isPrime(setBits(i))) count++;
        return count;
    }
};

// second solution "optimized"  
// we can use __builtin_popcount(i) to count the number of set bits in i
// and we can use a hash set to store the prime numbers as the maximum number of set bits is 31
// the time complexity is O(right - left)
// the space complexity is O(1)

class Solution {
public:
    int countPrimeSetBits(int left, int right) 
    {
        unordered_set<int> primes = 
        {2,3,5,7,11,13,17,19,23,29,31};

        int count = 0;

        for(int i = left; i <= right; i++)
            if(primes.count(__builtin_popcount(i)))
                count++;

        return count;
    }
};