#include <iostream>
using namespace std;

int  sum_digit(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n;
        n--;
    } 
    return sum;
}

int main()
{
    int n = 0;
    cout << "enter a number: ";
    cin >> n;
    int sum = sum_digit(n);
    cout << "sum of digits: " << sum << endl;
    return 0;
}
