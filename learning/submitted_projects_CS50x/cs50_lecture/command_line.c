#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // type ./command_line (any name with any numbers of spaces)
    // change i=1 and i<=argc to not say the file name
    for (int i = 0; i < argc ; i ++ )
    {
        printf("%s\n",argv[i]);
    }
}
