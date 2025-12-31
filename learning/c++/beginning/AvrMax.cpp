#include <iostream>
using namespace std;

int avg_value (int num)
{
    int sum_num = 0, i = 0;
    for ( ; num != 0; i++)
    {
        sum_num += num % 10;
        num /= 10;
    }
    int avg = sum_num/i;
    return avg;   
}

int max_value (int num)
{
    int max = 0, temp;
    while ( num != 0)
    {
        temp = num % 10;
        num /= 10;
        if ( max < temp)
        {
            max = temp;
        }
    }
    return max;
}

void AvgMaxR(int num, int &avg,int &max)
{
    avg = avg_value(num);
    max = max_value(num);
}

void AvgMaxP(int num, int *avg, int *max)
{
    *avg = avg_value(num);
    *max = max_value(num);
}

int main()
{
    int avgR=0,maxR=0;
    int avgP=0,maxP=0;
    
    int num;
    cout << "Enter a number: \n";
    cin >> num;
    AvgMaxR(num, avgR, maxR);
    cout << avgR << '\t' << maxR << endl;
    AvgMaxP(num, &avgP, &maxP);
    cout << avgP << '\t' << maxP << endl;
}
