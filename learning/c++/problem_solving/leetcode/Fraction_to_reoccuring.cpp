/*
https://leetcode.com/problems/fraction-to-recurring-decimal/description/

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses
If multiple answers are possible, return any of them.
It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
Note that if the fraction can be represented as a finite length string, you must return it.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(3)"
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        // sign
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // integer part
        result += to_string(num / den);

        long long rem = num % den;
        if (rem == 0) return result;

        result += ".";

        unordered_map<long long,int> seen;

        while (rem) {
            if (seen.count(rem)) {
                result.insert(seen[rem], "(");
                result += ")";
                break;
            }

            seen[rem] = result.size();
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};