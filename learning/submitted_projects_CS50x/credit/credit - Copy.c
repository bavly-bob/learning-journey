#include <cs50.h>
#include <stdio.h>
int getValue1(int x);
int getValue2(int x);
// name a fuction then put it
typedef void (*FunctionPointer)();
void repeat(int n, FunctionPointer func);
void check();
int codi(long n);
void iv();

long n;
int z;
long cal;
int sum1 = 0;
int sum2 = 0;

int main()
{


    n = get_long("Number: ");
    z = codi(n);
    cal = n;
    repeat(8, check);
    int k = sum1 + sum2;

    // first check that the sum is divisable by 10
    if ((k % 10) == 0)
    {
        // this is for amex
        if (z == 15)
        {
            if (n / 10000000000000 == 34 || n / 10000000000000 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                iv();
            }
        }

        // this is for visa
        else if (z == 16 || z == 13)
        {
            if ((n / 1000000000000000 == 4) || (n / 1000000000000 == 4))
            {
                printf("VISA\n");
            }

            // this  is for mastercard
            else if (n / 100000000000000 > 50 && n / 100000000000000 < 56)
            {
                printf("MASTERCARD\n");
            }

            else
            {
                iv();
            }
        }
        else
        {
            iv();
        }

    }

    else
    {
        iv();
    }
}

int getValue2(int x)
{
    if (x >= 5)
    {
        x = x * 2 - 9;
        return x;
    }
    else
    {
        return x * 2;
    }
}

int getValue1(int x)
{
    return x;
}

// the first gap put the amount of number
// the second gap put the name of the function
void repeat(int x, FunctionPointer func)
{
    for (int i = 0; i < x; i++)
    {
        func();
    }
}

void check()
{
    int y = cal % 10;
    sum1 += getValue1(y);
    cal = cal / 10;
    int x = cal % 10;
    sum2 += getValue2(x);
    cal = cal / 10;
}

int codi(long x)
{
    int count = 0;
    while (x > 0)
    {
        count++;
        x /= 10;
    }
    return count;
}

void iv()
{
    printf("INVALID\n");
}
