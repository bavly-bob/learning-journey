// Simple Mole Problem Solution
// Problem: Simple Mole
// Contest: Codeforces - Codeforces Round #277 (Div. 2)
// URL: https://codeforces.com/problemset/problem/472/A
/*
A mole is a small animal that lives underground. 
It has three legs of different lengths. 
The lengths of the legs are positive integers x, y and z. 
The mole wants to dig a triangular tunnel underground. 
The lengths of the sides of the triangular tunnel must be equal to the sums of the lengths of each two legs: x + y, y + z and z + x. 
#Input
The first line contains three space-separated integers a, b and c (1 ≤ a, b, c ≤ 100) — the lengths of the sides of the triangular tunnel.
#Output
If there exist such positive integers x, y and z 
that the lengths of the sides of the triangular tunnel are equal to a, b and c respectively,
print these integers x, y and z separated by spaces. 
If there are multiple solutions, print any of them. If there is no solution, print "Impossible" (without quotes).
*/
#include <iostream>
using namespace std;

int main() 
{
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2]; 
    float x = (arr[0] + arr[1] - arr[2]) / 2.0;
    float y = (arr[1] + arr[2] - arr[0]) / 2.0;
    float z = (arr[0] + arr[2] - arr[1]) / 2.0;

    if(x >= 0 && y >= 0 && z >= 0 
        && x+y+z != 0 
        && (x == (int)x && y == (int)y && z == (int)z))
        cout << x << " " << y << " " << z << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
