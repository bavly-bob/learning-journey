#include <iostream>
using namespace std;



void frequencyR(long long& num, int& sd,int& frequency, bool& exists)
{ 
    int temp;
    while ( num != 0)
    {
        temp = num % 10;
        if ( sd == temp)
        {
            frequency ++;
        }
        num /= 10;
    }
    frequency > 0 ? exists = true: exists = false;
}

void frequencyP(long long* num, int* sd, int* frequency, bool* exists)
{
    int temp;
    while ( *num != 0)
    {
        temp = *num % 10;
        if ( *sd == temp)
        {
            (*frequency) ++;
        }
        (*num) /= 10;
    }
    (*frequency) > 0 ? *exists = true: *exists = false;
}

int main()
{
    long long num = 0; int sd = 0, freqP=0, freqR=0 ; bool existsP,existsR;

    cout << "Enter a number and sd: \n";
    cin >> num >> sd;
    long long numP = num; int sdP = sd;
    long long numR = num; int sdR = sd;

    frequencyR(numR,sdR,freqR,existsR);
    cout << freqR <<'\t'<< existsR   << endl;
    frequencyP(&numP , &sdP,&freqP, &existsP);
    cout << freqP <<'\t'<< existsP   << endl;
    return 0;
}

