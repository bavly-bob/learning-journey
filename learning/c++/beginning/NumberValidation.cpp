#include <iostream>
using namespace std;

bool numbervalidation(int number , int base)
{
    while (number > 0) 
    {
        if (number % 10 >= base) 
        {
            return false;
        }
        number /= 10;
    }
    return true;
    
}

int main()
{
    cout << "Enter a number and base: ";
    int number , base;
    cin >> number;
    if (numbervalidation(number, base)) 
    {
        cout << "The number is valid." << endl;
    } 
    else 
    {
        cout << "The number is invalid." << endl;
    }
}
