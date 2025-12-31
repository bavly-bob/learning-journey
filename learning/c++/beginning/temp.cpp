#include <iostream>

using namespace std;

int main()
{
    double temp = 0;
    cout << "enter temprature in Fahrihength:";
    cin  >> temp;
    double cels = (temp -32) * 5/9;
    cout << "the temprature in celis is:"<< cels << endl;
} 