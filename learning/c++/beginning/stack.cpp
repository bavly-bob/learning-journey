#include <iostream>
using namespace std;
#define MAX 100

class Stack
{
    int Lptr;
public:
    int y;
    int a[100];
    Stack() 
    { 
        Lptr = 0; 
    }

    bool Push(int x)
    {
        if (Lptr > MAX - 1)
        {
            cout << "Stack is FULL" << endl;
            return false;
        }
        else
        {
            a[Lptr] = x;
            Lptr ++;
            cout << x << "\t Added to Stack\n";
            return true;
        }
    }

    int Pop()
    {
        if (Lptr <= 0)
        {
            cout << "Stack Empty";
            return 0;
        }
        else
        {
            y = a[Lptr - 1];
            Lptr --;
            cout << y << "\tPopped from stack" << endl;
            return y;
        }
    }

    display()
    {
        for (int i = Lptr - 1 ; i >= 0 ; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout << s.Pop();
}