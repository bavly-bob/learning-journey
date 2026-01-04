/*
leetcode problem link: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
Given an array of numbers arr. A sequence of numbers is called an arithmetic progression
if the difference between any two consecutive elements is the same.
Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.
*/

#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int tmp = arr[1] -  arr[0];
        for(int i = 1; i<arr.size()-1; i++)
        {
            if(tmp != arr[i+1] - arr[i]) return false;
        } 
        return true;    
    }
};
// Time Complexity: O(n log n)
// Space Complexity: O(1)

// another approach using hash set
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return true; // 1 or 2 elements always form AP

        int mn = arr[0], mx = arr[0];
        for (int x : arr) {
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }

        if ((mx - mn) % (n - 1) != 0) return false; // diff must be integer

        int diff = (mx - mn) / (n - 1);
        unordered_set<int> seen;

        for (int x : arr) {
            if ((x - mn) % diff != 0) return false; // not aligned
            if (seen.count(x)) return false;        // duplicate
            seen.insert(x);
        }

        return true;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)