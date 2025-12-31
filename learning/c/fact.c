#include <cs50.h>
#include  <stdio.h>

int main()
{
    int fact = get_int("Number: ");
    const int constt = fact;
    for ( int i = 1;i < constt;i++)
    {
        fact *= i;
    }
    printf("%i\n",fact);
}

