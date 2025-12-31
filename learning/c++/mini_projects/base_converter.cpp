// base_converter.cpp
// A program to convert numbers between bases 2 and 16

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string convert(string num, int to_base, int initial_base);
void between2and16(int base);
void isbasewrong(string num, int initial_base);

string digits = "0123456789ABCDEF";
string result;

int main() 
{
    string num;
    int base, initial_base;
    
    cout << "This program converts any base number to any base between 2 and 16" << endl;
    
    cout << "Enter the initial base: ";
    cin >> initial_base;
    between2and16(initial_base);
    
    cout << "What base do you want to convert to? ";
    cin >> base;
    between2and16(base);
    
    cout << "Enter a number: ";
    cin >> num;
    isbasewrong(num, initial_base);
    
    if(initial_base == base) 
    {
        result = num;
    }
    else
    {
        result = convert(num, base, initial_base);
    }
    cout << "The number in base " << base << " is: " << result << endl;

    return 0;
}

string convert(string num, int to_base, int initial_base)
{
    long long dec = 0;

    // convert from initial_base to decimal
    for (char c : num) 
    {
        int value = digits.find(toupper(c));
        dec = dec * initial_base + value;
    }

    // convert decimal to to_base
    if (dec == 0) return "0";

    string result = "";
    while (dec > 0) 
    {
        result = digits[dec % to_base] + result;
        dec /= to_base;
    }
    return result;
}

void isbasewrong(string num, int initial_base) 
{
    for (char c : num) 
    {
        int value = digits.find(toupper(c));
        if (value == string::npos || value >= initial_base) 
        {
            cout << "The number is not valid in base " << initial_base << endl;
            exit(1);
        }
    }
}

void between2and16(int base) 
{
    if (base < 2 || base > 16) {
        cout << "Base must be between 2 and 16" << endl;
        exit(1);
    }
}