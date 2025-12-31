#include <iostream>
using namespace std;

int Occurrence(long number , int digit)
{
    int count = 0;
    while (number > 0) 
    {
        if (number % 10 == digit) 
        {
            count++;
        }
        number /= 10;
    }
    return count;
}

int main()
{
    cout << "Enter a number and digit: ";
    long number;
    int digit;
    cin >> number >> digit;
    int result = Occurrence(number, digit);
    cout << "The digit " << digit << " occurs " << result << " times in the number " << number << "." << endl;
}
