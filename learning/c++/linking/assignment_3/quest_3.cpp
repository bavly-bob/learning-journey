#include <iostream>
#include <string>
#include <cctype>
#include "header.h"
using namespace std;

int num_words(const char str[])
{
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && !inWord)
        {
            inWord = true;
            count++;
        }
        else if (str[i] == ' ')
        {
            inWord = false;
        }
    }

    return count;
}

string replace_blanks_with_underscores(const char str[])
{
    string result;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            result += '_';
        }
        else
        {
            result += str[i];
        }
    }
    return result;
}

string remove_punctuation(const char str[])
{
    string result;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!ispunct(str[i]))
        {
            result += str[i];
        }
        else
        {
            result += ' ';
        }
    }
    return result;
}

void quest_3()
{
    while (true)
    {
        int quest3_choice;
        cout << "Choose an option:\n";
        cout << "-------------------------------------\n"; 
        cout << "1. Count number of words in a string\n";
        cout << "2. Replace blanks with underscores in a string\n";
        cout << "3. remove punctuation from a string\n";
        cout << "4. Exit\n";
        cout << "-------------------------------------\n";
        
        cout << "Enter your choice: ";
        cin >> quest3_choice;
        cin.ignore(); // clear newline left by cin
        
        switch (quest3_choice)
        {
            case 1:
            {
                char input[200];
                cout << "Enter a string: ";
                cin.getline(input, 200);
                int wordCount = num_words(input);
                cout << "Number of words: " << wordCount << endl;
                break;
            }
            case 2:
            {
                char input[200];
                cout << "Enter a string: ";
                cin.getline(input, 200);
                string modifiedString = replace_blanks_with_underscores(input);
                cout << "Modified string: " << modifiedString << endl;
                break;
            }
            case 3:
            {
                char input[200];
                cout << "Enter a string: ";
                cin.getline(input, 200);
                string modifiedString = remove_punctuation(input);
                cout << "Modified string: " << modifiedString << endl;
                break;
            }
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << endl;
    }
    
}