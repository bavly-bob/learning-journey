#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x[100] = {0}; // initialized to zero
    int *y = x;
    for (int i = 0; i < 100; i++)
    {
        printf("Value: %i\t Address: %p\n", x[i], &y[i]);
    }
}
