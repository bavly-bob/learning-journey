#include "header.h"

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void fil_arr(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10 + 1;
}

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void quest_2()
{
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    int* arr = new int[size];

    fil_arr(arr, size);
    sort(arr, size);
    display(arr, size);
    delete[] arr;
}