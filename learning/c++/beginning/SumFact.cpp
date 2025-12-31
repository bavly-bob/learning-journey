#include <iostream>
using namespace std;


int  SumFact(int n)
{
    int fact = 1;
    while (n != 1)
    {
        fact *= n;
        n--;
    } 
    return fact;
}

int main()
{
    int n = 0;
    cout << "enter a number: ";
    cin >> n;
    int sum = SumFact(n);
    cout << "sum of digits: " << sum << endl;
    return 0;
}
