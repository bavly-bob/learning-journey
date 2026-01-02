// https://leetcode.com/problems/divide-two-integers/
// Divide two integers without using multiplication, division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].

#include <climits>
#include <cstdlib>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long a = llabs(dividend);
        long long b = llabs(divisor);

        int result = 0;

        while (a >= b) {
            long long temp = b;
            int multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        return ((dividend < 0) ^ (divisor < 0)) ? -result : result;
    }
};
