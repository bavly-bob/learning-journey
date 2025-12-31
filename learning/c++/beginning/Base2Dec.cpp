#include <iostream>
#include <cmath>
using namespace std;

int Base2Dec(int num, int base)
{
    int dec = 0, power = 0;
    while (num != 0) 
    {
        int value = num % 10; // Get the last digit 
        dec += value * pow(base, power); 
        num /= 10;
        power++;
    }
    return dec;
}

int main()
{
    cout << "enter a number and its base:";
    int num, base;
    cin >> num >> base;
    cout << "the decimal value is: " << Base2Dec(num, base) << endl;
    return 0;
}
