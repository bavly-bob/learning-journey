#include <iostream>
#include <string>
#include "header.h"
using namespace std;

// Function to calculate string length
int getlength(const char str[])
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

// Function to copy one string into another
void copystring(char cpy_str[], const char source_str[])
{
    while (*source_str != '\0')
    {
        *cpy_str = *source_str;
        cpy_str++;
        source_str++;
    }
    *cpy_str = '\0';
}

// Function to concatenate two strings
void concatstring(char combined[], const char s1[], const char s2[])
{
    while (*s1 != '\0')
    {
        *combined = *s1;
        combined++;
        s1++;
    }
    while (*s2 != '\0')
    {
        *combined = *s2;
        combined++;
        s2++;
    }
    *combined = '\0';
}

// Helper function to safely get user input with overflow check
void safeInput(char str[], int size, const string &prompt)
{
    while (true)
    {
        cout << prompt;
        cin.getline(str, size);

        if (cin.fail())
        {
            cout << "Input too long! Please enter fewer than " << size - 1 << " characters.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            break;
        }
    }
}

// The main question function
void quest_1()
{
    cout << "=== String Length, Copy, and Concatenate ===\n";

    while (true)
    {
        cout << "\n-------------------------------------------\n";
        cout << "1. Calculate String Length\n";
        cout << "2. Copy String\n";
        cout << "3. Concatenate Strings\n";
        cout << "4. Exit\n";
        cout << "-------------------------------------------\n";
        cout << "Enter your choice (1-4): ";

        int quest1_choice;
        cin >> quest1_choice;
        cin.ignore(); // clear leftover newline

        switch (quest1_choice)
        {
            case 1:
            {
                char inputString[100];
                safeInput(inputString, 100, "Enter a string: ");
                cout << "Length of the string: " << getlength(inputString) << endl;
                break;
            }

            case 2:
            {
                char source_str[100];
                char cpy_str[100];
                safeInput(source_str, 100, "Enter a string to copy: ");
                copystring(cpy_str, source_str);
                cout << "Copied string: " << cpy_str << endl;
                break;
            }

            case 3:
            {
                char s1[50], s2[50], combined[100];
                safeInput(s1, 50, "Enter first string: ");
                safeInput(s2, 50, "Enter second string: ");
                concatstring(combined, s1, s2);
                cout << "Concatenated string: " << combined << endl;
                break;
            }

            case 4:
                cout << "Exiting quest_1...\n";
                return; 

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
