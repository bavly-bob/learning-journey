#include "header.h"

void sum_even_and_odd(int n[], int size, int &sum_even, int &sum_odd)
{
    sum_even = 0;
    sum_odd = 0;
    for (int i = 0; i < size; i++)
    {
        if (n[i] % 2 == 0)
        {
            sum_even += n[i];
        }
        else
        {
            sum_odd += n[i];
        }
    }
}

void fill_array_up_to_30(int n[], int size, int& sum_even, int& sum_odd)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        n[i] = rand() % 30 +1;
    }
    sum_even_and_odd(n, size, sum_even, sum_odd);
}



void quest_1()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* n = new int[size];
    int sum_even, sum_odd;
    fill_array_up_to_30(n, size, sum_even, sum_odd);
    display(n,size);
    cout << "Sum of even numbers: " << sum_even << endl;
    cout << "Sum of odd numbers: " << sum_odd << endl;
    delete[] n;   
}