#include <iostream>
using namespace std;

int main()
{
    // Implicit conversion from int to bool
    bool a = 10;  // Non-zero integer converts to true
    bool b = 0;   // Zero converts to false
    cout << "a: " << a << ", b: " << b << endl;
    int x = 10;  // Implicit conversion from bool to int
    int y = 0;  
    cout << "x: " << x << ", y: " << y << endl;

    void z = 10; // Error: cannot convert int to void
    cout << "z: " << z << endl;
}
