#include <stdio.h>

//name a fuction then put it
typedef void (*FunctionPointer)();

//the first gap put the amount of number
//the second gap put the name of the function
void repeat(int n, FunctionPointer func)
{
    for (int i = 0; i < n ; i++)
    {
        func();
    }
}
