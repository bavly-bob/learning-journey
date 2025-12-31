#include <iostream>
#include <cmath>
using namespace std;

int Dec2Base(int dec, int base)
{
    int number = 0, power = 0;
    while (dec != 0) 
    {
        int remainder = dec % base;
        number += remainder * pow(10, power);
        dec /= base;
        power++;
    }
    return number;
}

int main()
{
    cout << "enter a number and its base:";
    int dec, base;
    cin >> dec >> base;
    cout << "the decimal value is: " << Dec2Base(dec, base) << endl;
    return 0;
}