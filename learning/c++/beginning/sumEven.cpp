#include <iostream>
using namespace std;

void sum_even(int num, int* min, int* sum)
{
    int temp;
    while(num != 0)
    {
        temp = num % 10;
        if( (temp % 2) == 0) *sum += temp;
        if( *min > temp) *min = temp;
        num /= 10;
    }
    
}

int main()
{
    int num , min = 10,sum=0;
    cout << "enter a number: ";
    cin >> num;
    sum_even(num, &min,&sum);
    cout << "even number sum: " << sum << '\t' << "the min value is: " << min <<endl;
    
}
