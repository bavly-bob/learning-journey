#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Hello, world \n";
    cout << "how old are you: ";
    cin  >> age;
    cout << "Age: " << age << endl;

    if (age < 18)
    {
        cout << "not\n";
    }
    else
    {
        cout << "allow\n";
    }
}
