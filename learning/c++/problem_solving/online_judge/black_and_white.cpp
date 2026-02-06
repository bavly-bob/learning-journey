// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2172
/*
You are visiting the Centre Pompidou which contains a lot of modern paintings. In particular you
notice one painting which consists solely of black and white squares, arranged in rows and columns like
in a chess board (no two adjacent squares have the same colour). By the way, the artist did not use
the tool of problem A to create the painting.
Since you are bored, you wonder how many 8 × 8 chess boards are embedded within this painting.
The bottom right corner of a chess board must always be white.
Input
The input contains several test cases. Each test case consists of one line with three integers n, m and
c. (8 ≤ n, m ≤ 40000), where n is the number of rows of the painting, and m is the number of columns
of the painting. c is always 0 or 1, where 0 indicates that the bottom right corner of the painting is
black, and 1 indicates that this corner is white.
The last test case is followed by a line containing three zeros.
Output
For each test case, print the number of chess boards embedded within the given painting.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    do
    {
        cin >> n >> m >>c;
        if(n == 0 && m == 0 && c == 0)
            break;
        if(n >=8 && m >=8)
        {
            int ans = (n - 7) * (m - 7);
            if(c == 1)
                cout << ans/2 + ans%2 << "\n";
            else
                cout << ans/2 << "\n";
        }
        else
            cout << "0\n";
    } while (true);

    return 0;
}