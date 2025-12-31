#include <iostream>
using namespace std;
#define MAX 100

class Queue
{
    int Lptr;
public:
    int y;
    int a[MAX];
    Queue() 
    { 
        Lptr = 0; 
    }

    bool Enqueue(int x)
    {
        if (Lptr >= MAX - 1)
        {
            cout << "Queue is FULL" << endl;
            return false;
        }
        else
        {
            a[Lptr] = x;
            Lptr ++;
            cout << x << "\t Added to Q\n";
        }
        return true;
    }

    int Dequeue()
    {
        int i;
        if (Lptr <= 0)
        {
            cout << "Queue Empty";
            return 0;
        }
        else
        {
            y = a[0];
            for (i = 0; i < Lptr; i++)
                a[i] = a[i + 1];

            Lptr = Lptr - 1;
            cout << y << "\tDequeued from queue" << endl;
            return y;
        }
    }
};
