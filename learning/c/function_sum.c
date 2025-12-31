#include <stdio.h>

int getValue(int x);

int main() {
    int sum = 0;

    // Example: call getValue 5 times
    for (int i = 1; i <= 5; i++)
    {
        sum += getValue(i);
    }

    printf("Total sum = %i\n", sum);




    //count digits
    int n = 1234;
    int codi = 0;
    while (n != 0)
    {
        n = n / 10;
        codi++;
    }
    printf("%i\n",codi);
}



int getValue(int x)
{
    return x * 2;
}

