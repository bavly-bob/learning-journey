#include <iostream>
#include <cmath>
using namespace std;

string Dec2Base(int dec, int base)
{
    string digits= "0123456789ABCDEF";
    string number = "";
    while (dec != 0) 
    {
        number = digits[dec % base] + number;
        dec /= base;
    }
    return number;
}

int main()
{
    cout << "enter a decimal number and which base to convert to:";
    int dec, base;
    cin >> dec >> base;
    cout << "the  value is: " << Dec2Base(dec, base) << endl;
    return 0;
}