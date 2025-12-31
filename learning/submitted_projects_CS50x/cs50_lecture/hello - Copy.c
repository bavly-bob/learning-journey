#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("hello, world\n");
    string answer = get_string("what is your name? ");
    printf("hello, %s\n", answer );
}
