#include "header.h"
#include <iostream>
using namespace std;

int main()
{
    int choice = 0;
   
    while (choice != 4)
    {
        cout << "Select a question to execute (1-3): " << endl;
        cout << "1. Question 1" << endl;
        cout << "2. Question 2" << endl;
        cout << "3. Question 3" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                quest_1();
                cout << endl << "--------------------------------------------------"<< endl;
                break;
            case 2:
                quest_2();
                cout << endl <<"--------------------------------------------------"<< endl;
                break;
            case 3:
                quest_3();
                cout << endl << "--------------------------------------------------"<< endl;
                break;
        }

        choice == 4? : choice = 1; // Reset choice to continue the loop
    }

    cout << "goodbye!" << endl << endl;

    return 0;
}