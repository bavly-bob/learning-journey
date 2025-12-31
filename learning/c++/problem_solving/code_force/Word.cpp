#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int upper = 0, lower = 0;
    for(char c: str)
    {
        if(isalpha(c))
        {
            if(islower(c)) lower++;
            else upper ++;
        }
    }

    string result = "";
    if(upper > lower)
        for(char c : str)
            result += toupper(c);
    else 
        for(char c : str)
            result += tolower(c);

    cout << result;
}