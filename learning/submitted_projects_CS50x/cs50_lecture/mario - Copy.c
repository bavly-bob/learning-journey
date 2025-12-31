#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int dollar = 1;
    while(true)
    {
        char c = get_char("here is %i, do you want to double it?\n",dollar);
        if (c=='y')
          dollar *=2;

        else (c=='n')
          break;
    }
}
