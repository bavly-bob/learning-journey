#include <iostream>
using namespace std;


void Sec2HrMinP(int* sec , int* min , int* hour)
{
    *min += *sec / 60;
    *sec = *sec % 60;

    *hour += *min / 60;
    *min = *min % 60;
}
void Sec2HrMinR(int& sec , int& min , int& hour)
{
    min += sec / 60;
    sec  = sec % 60;

    hour += min / 60;
    min   = min % 60;
}

int main()
{
    int sec = 0, minP=0,hourP=0, minR=0,hourR=0;
    
    cout << "Enter a number in seconds:" << endl;
    cin  >> sec;
    int secP = sec;
    int secR = sec;

    cout << "Seconds" << '\t' << "Minutes" << '\t' << "Hours\n";
    Sec2HrMinP(&secP,&minP,&hourP);
    cout << secP <<'\t'<< minP << '\t' << hourP << endl;

    Sec2HrMinR(secR, minR, hourR);
    cout << secR <<'\t'<< minR << '\t' << hourR << endl;
    
}
