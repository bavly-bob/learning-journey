// LeetCode Problem: Rotate Image
// Problem Link: https://leetcode.com/problems/rotate-image/
// Rotate the image by 90 degrees (clockwise).

#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> copy = matrix;
        for(int row = 0; row < n; row++)
            for(int place = 0; place < n; place++)
            {
                copy[place][n - row -1] =  matrix[row][place];
            }
        matrix = copy;
    }
};

// Alternative in-place solution
class Solution 
{
private:
    void reverseRow(vector<int>& row) 
    {
        int left = 0, right = row.size() - 1;
        while(left < right) {
            swap(row[left], row[right]);
            left++;
            right--;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        
        // Step 1: Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for(int i = 0; i < n; i++) {
            reverseRow(matrix[i]);
        }
    }
};
