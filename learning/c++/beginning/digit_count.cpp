#include <iostream>
using namespace std;

int main()
{
    int number, digit_count = 0;
    cout << "Enter a number: ";
    cin >> number;
    if (number >= 0 && number <= 99999)
    {
        while (number != 0)
        {
            number /= 10;
            digit_count++;
        }
        cout << "Number of digits: " << digit_count << endl;
        
    }
    else
    {
        cout << "Number out of range. Please enter a number between 0 and 99999." << endl;
        
    }
    
}
