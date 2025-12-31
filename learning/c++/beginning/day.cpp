#include <iostream>
using namespace std;

int main()
{
    string day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "Enter a number (1-7): ";
    int n;
    cin >> n;
    if (n >= 1 && n <= 7)
    {
        cout << "The day is " << day[n-1] << endl;
        switch(n) {
        case 1:
            cout << "It's the first day of the week!" << endl;
            break;
        case 7:
            cout << "It's the last day of the week!" << endl;
            break;
        default:
            cout << "It's a weekday." << endl;
            break;
        }
    }
    else
    {
        cout << "Invalid input! Please enter a number between 1 and 7." << endl;
    }
    

    return 0;
}
