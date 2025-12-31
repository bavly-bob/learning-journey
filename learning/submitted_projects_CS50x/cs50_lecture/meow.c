#include <stdio.h>
#include <cs50.h>

void meow(int n);

int x;

int main(void)
{
  do
  {
     x = get_int("how many meows do you need?  ");
  }
  while (x < 0 );

    meow(x);
}





























void meow(int n)
{
    for (int i = 0 ; i < n ; i++)
    printf("meow\n");
}
