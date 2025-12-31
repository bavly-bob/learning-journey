#include <iostream>
#include <cmath>
using namespace std;

void pattern1()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5;j++)
        {
            if (j==i)       cout << " 0 ";
            else if (j < i) cout << " 1 ";
            else            cout << " 2 ";
            
        }
        cout << endl;
    }
     cout << endl;
}

void pattern2()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5;j++)
        {
            if (j <= i && (i%2)==1) cout << " $ ";
            else if (j <= i && (i%2)==0) cout << ' ' <<j+1<< ' ';
        }
        cout << endl;
    }
     cout << endl;
}

void pattern3()
{
    
    for(int i = 0; i < 5; i++)
    {
        int k = 1;

        for (int s = 0; s < 4 - i; s++) cout << "   "; // printing spaces

        for(int j = 0; j < 5;j++)
        {
            if (j <= i && (i%2)==1)        cout << " $ ";
            else if (j <= i && (i%2)==0)   cout << " "<< k++ << " ";
        }
        cout << endl;
    }
     cout << endl;
}

void pattern4()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5;j++)
        {
            if ( j <= (4-i)) cout << " " << pow(2,(4-j-i)) << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void pattern5()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5;j++)
        {
            if (j <= i && i==2) cout << " * ";
            else if (j <= i) cout << ' ' <<j+1<< ' ';
        }
        cout << endl;
    }
     cout << endl;
}

void pattern6()
{
    for(int i = 0; i < 5; i++)
    {
        int k = 0;
        for (int s = 0; s < i; s++) cout << "   "; // printing spaces

        for(int j = 0; j < 5;j++)
        {
            if (j >= i) cout << ' ' << pow(2,k++)<<' ';
        }
        
        cout << endl;
    }
    cout << endl;
}

int main()
{
    pattern1(); 
    pattern2();
    pattern3();
    pattern4();
    pattern5(); 
    pattern6();
}
