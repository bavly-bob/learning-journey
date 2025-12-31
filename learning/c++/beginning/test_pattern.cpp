#include <iostream>
using namespace std;

void fill(char arr[][]) 
{
    for(int i = 0; i < 6; i++) 
    {
        for(int j = 0; j < 6; j++)
        {
            if ((i % 2) == 0)
                arr[i][j] = '#';
            else
                arr[i][j] = (char)(i + j + '0');
        }
    }
}

void display(char arr[][]) 
{
    for(int i = 0; i < 6; i++) 
    {
        for(int j = 0; j < 6-i; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() 
{
    char pattern[6][6];
    fill(pattern);
    display(pattern);
    return 0;
}
