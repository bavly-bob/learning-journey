#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== STRING OPERATIONS MENU =====\n";
        cout << "1. String length, copy, and concatenate \n";
        cout << "2. Repeated string separation \n";
        cout << "3. String word counter, replace spaces with under and remove punctation\n";
        cout << "4. billioners sorting\n";
        cout << "5. Exit\n";
        cout << "==================================\n";
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;
        cin.ignore(); // clear newline left by cin

        switch (choice)
        {
        case 1:
            quest_1();
            break;
        case 2:
            quest_2();
            break;
        case 3:
            quest_3();
            break;
        case 4:
            quest_4();
            break;
        default:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        }
    }

    return 0;
}
