#include <cs50.h>
#include <stdio.h>

typedef void (*FunctionPointer)();
void repeat(int n, FunctionPointer func)
{
    for (int i = 0; i < n; i++)
    {
        func();
    }
}

void p();
void spx();

int main()
{
    int x;

    do
    {

        x = get_int("height: ");
    }
    while (x < 1 || x > 8);

    int i;
    for (i = 0; i < x; i++)
    {

        repeat(x - i - 1, spx);
        repeat(1 + i, p);
        printf("\n");
    }
}

void p()
{
    printf("#");
}

void spx()
{
    printf(" ");
}
