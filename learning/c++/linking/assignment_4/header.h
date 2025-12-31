#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quest_1();
void quest_2();
void quest_3();

static void display(int n[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << n[i] << "\t";
    }
    cout << endl;
}


