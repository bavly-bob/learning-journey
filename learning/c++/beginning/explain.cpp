#include <iostream>
using namespace std;

void swipe(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main ()
{
    int a = 5, b = 10;
    cout << "Before swipe: a = " << a << ", b = " << b << endl;
    swipe(a, b);
    cout << "After swipe: a = " << a << ", b = " << b << endl;
    return 0;

}