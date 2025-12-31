#include <iostream>
#include <string>
#include <limits>  // for numeric_limits
using namespace std;

int main() {
    int age;
    string name;

    cout << "Enter your age: ";
    cin >> age;     // reads the number but leaves '\n' in the buffer

    cout << "Enter your name: ";
    getline(cin, name);   // <-- problem happens here
    cout << "Without cin.ignore(), name is: '" << name << "'" << endl;

    // Now let's fix it:
    cout << "\nTry again (with cin.ignore)" << endl;

    cout << "Enter your age: ";
    cin >> age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "With cin.ignore(), name is: '" << name << "'" << endl;

    return 0;
}
