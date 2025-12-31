#include "header.h"


int main()
{
    srand(time(0)); // initialize random seed once

    int choice;

    do
    {
        cout << "\nSelect an assignment to run (1-4):\n";
        cout << "1. Assignment 4 - Question 1 (Sum even and odd numbers)\n";
        cout << "2. Assignment 4 - Question 2 (Sort array)\n";
        cout << "3. Assignment 4 - Question 3 (Common elements of two arrays)\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1: 
            {
                quest_1();
                break;
            }

            case 2: {
                quest_2();
                break;
            }

            case 3: {
                quest_3();
                break;
            }

            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }

    } while (choice != 4);

    return 0;
}
