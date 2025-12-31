// last_digit_of_large_number.cpp
// codewar k: https://www.codewars.com/kata/5511b2f550906349a70004e1
// Given two non-negative integers x and y represented as strings,
// return the last digit of x raised to the power of y (i.e., x^y).


// this solution handles very large numbers by using modular arithmetic
// this solution runs in O(n) time complexity where n is the length of the exponent string
// and O(1) space complexity.
// but there is a more optimal solution that runs in O(1) time and O(1) space complexity.

#include <iostream>
#include <string>
using namespace std;

// Compute large number mod m
int modLargeNumber(const string& num, int m) {
    int result = 0;
    for (char c : num) {
        result = (result * 10 + (c - '0')) % m;
    }
    return result;
}

// Compute last digit of x^y
int last_digit(const string &str1, const string &str2) {
    if (str2 == "0") return 1; // anything^0 = 1
    
    int x = str1.back() - '0'; // last digit of base
    
    if (x == 0 || x == 1 || x == 5 || x == 6) return x;
    
    int cycle_length;
    if (x == 4 || x == 9) cycle_length = 2;
    else if (x == 2 || x == 3 || x == 7 || x == 8) cycle_length = 4;
    else cycle_length = 1; // for 0,1,5,6 already handled
    
    int exponent_mod = modLargeNumber(str2, cycle_length);
    if (exponent_mod == 0) exponent_mod = cycle_length;
    
    // Compute last digit using small power
    int result = 1;
    for (int i = 0; i < exponent_mod; i++) {
        result = (result * x) % 10;
    }
    
    return result;
}


// here is the better solution 
int last_digit_optimized(const string &str1, const string &str2) 
{
    int cycles[10][4] = 
    {
        {0},        // 0
        {1},        // 1
        {2,4,8,6},  // 2
        {3,9,7,1},  // 3
        {4,6},      // 4
        {5},        // 5
        {6},        // 6
        {7,9,3,1},  // 7
        {8,4,2,6},  // 8
        {9,1}       // 9
    };
    int cycle_length[10] = {1,1,4,4,2,1,1,4,4,2};

    int x = str1.back() - '0';
    int len = cycle_length[x];
    int exp_mod = modLargeNumber(str2, len);
    if (exp_mod == 0) exp_mod = len;
    int last_digit = cycles[x][exp_mod - 1];
    return last_digit;
}
