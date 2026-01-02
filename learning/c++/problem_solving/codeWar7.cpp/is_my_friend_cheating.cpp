/*
codewars.com/kata/5547cc7dcad755e480000004
Is my friend cheating?
John and Mary want to play a game. The rules of the game are as follows:
They pick a number n. Then they write down the numbers 1 to n on a piece of paper.
After that, they each pick a number from the paper (let's call them a and b).
If the sum of all the numbers remaining on the paper equals a * b, Mary wins. Otherwise, John wins.
*/

#include <vector>

using namespace std;

class RemovedNumbers
{
public:
    static vector<vector<long long>> removNb(long long n)
    {
        vector<vector<long long>> result;
        long long S = n * (n + 1) / 2; // sum of 1..n

        for (long long a = 1; a <= n; ++a) {
            long long numerator = S - a;
            long long denominator = a + 1;
            if (numerator % denominator == 0) { // integer check
                long long b = numerator / denominator;
                if (b <= n) {
                    result.push_back({a, b});
                }
            }
        }

        return result;
    }
};
