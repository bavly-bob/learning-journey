#include <stdio.h>

// Define a struct to hold two integers
typedef struct {
    int a;
    int b;
} Pair;

// Function to swap values and return a Pair
Pair swap(int x, int y)
{
    Pair result;
    result.a = y;
    result.b = x;
    return result;
}

int main()
{
    int x = 1;
    int y = 2;
    printf("Before swap: %d, %d\n", x, y);

    Pair swapped = swap(x, y);
    x = swapped.a;
    y = swapped.b;

    printf("After swap: %d, %d\n", x, y);
    return 0;
}
