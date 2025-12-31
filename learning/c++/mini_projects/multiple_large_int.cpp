// multiple_large_int.cpp
// This program multiplies two large integers represented as strings
// and outputs the result as a string. It handles integers larger than
// standard data types by performing multiplication digit by digit.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Store reversed digits (LSD first)
    vector<int> num1, num2;
    for (int i = s1.size() - 1; i >= 0; i--)
        num1.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--)
        num2.push_back(s2[i] - '0');

    vector<int> result(num1.size() + num2.size() + 1, 0);

    // Long multiplication
    for (int i = 0; i < num1.size(); i++) {
        for (int j = 0; j < num2.size(); j++) {
            result[i + j] += num1[i] * num2[j];

            // Carry
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10;
        }
    }

    // Remove leading zeros
    int k = result.size() - 1;
    while (k > 0 && result[k] == 0) k--;

    // Print reversed back
    for (; k >= 0; k--)
        cout << result[k];
}
