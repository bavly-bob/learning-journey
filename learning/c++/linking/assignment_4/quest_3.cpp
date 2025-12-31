#include "header.h"

void common(int arr1[], int arr2[], int common_elements[], int size1, int size2, int common_size,int& index)
{
    index = 0;
    for(int i = 0; i < size1; i++)
        for(int j=0; j < size2; j++)
            if(arr1[i] == arr2[j])
            {
                common_elements[index] = arr1[i];
                index++;
            }
}

void fil_arr_10_to_90(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 81 + 10;
}



void quest_3()
{
    srand(time(0));

    int size1, size2,index;
    cout << "Enter the size of first array: ";
    cin >> size1;
    cout << "Enter the size of second array: ";
    cin >> size2;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    int common_size = size1 > size2 ? size2 : size1;
    int* common_elements = new int[common_size];

    fil_arr_10_to_90(arr1, size1);
    fil_arr_10_to_90(arr2, size2);

    common(arr1, arr2, common_elements, size1, size2, common_size,index);
    
    display(arr1, size1);
    display(arr2, size2);
    display(common_elements, index);


    delete[] arr1;
    delete[] arr2;
    delete[] common_elements;
}

