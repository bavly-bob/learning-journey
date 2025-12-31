#include <iostream>
using namespace std;

int main()
{
    cout << 2/3 <<endl;  // cout print int only
    cout << 2/3.0 <<endl;// cout foalt

    string name;
    cout << "what is your name: ";
    getline(cin,name); //can't use ( cin << name ) to get full name
    cout << "hello, " << name <<endl;
    
    int num[4];
    for (int i=0; i<4; i++)
    {
        num[i] = 0; // initialize array with no garbage value
    }
    return 0;
}
