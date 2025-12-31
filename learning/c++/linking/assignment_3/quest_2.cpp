#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void quest_2()
{
    char input[100];
    safeInput(input, 100, "Enter a string: ");

    cout << "\nSeparated repeated sequences:\n";

    int i = 0;
    while (input[i] != '\0')
    {
        cout << input[i];
        if (input[i] != input[i + 1])
        {
            cout << endl;
        }
        i++;
    }
}
