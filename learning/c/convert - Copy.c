#include <stdio.h>
#include <stdlib.h> // for atoi

int main()
{
    char str[] = "1234";
    int x = atoi(str); // convert string to int
    printf("%d\n", x); // prints 1234
}

int main()
{
    int x = 1234;
    char str[10];
    sprintf(str, "%d", x); // convert integer to string
    printf("%c\n", str[1]); // print second character (which is '2')
}
