#include <iostream>
#include <cmath>

using namespace std;

const int rows = 5, cols = 5;

void display(string pattern[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            cout << pattern[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void pattern1(string pattern[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            if ( j == i) pattern[i][j] = " 0 ";
            else if ( j < i) pattern[i][j] = " 1 ";
            else pattern[i][j] = " 2 ";
        }
    }
}

void pattern2(string pattern[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            if (j <= i)
            {
                if ( (i % 2) == 0) pattern[i][j] = " " + to_string(j+1) + " ";
                else pattern[i][j] = " $ ";
            }
            else pattern[i][j] = "   ";
        }
    }
}

void pattern3(string pattern[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        int k = 1;
        for(int j = 0; j < cols;j++)
        {
            if ( j >= (rows- i-1)) 
            {
                if ( (i%2)==0) pattern[i][j] = " " + to_string(k++) + " "; 
                else pattern[i][j] = " & ";
            }
            else pattern[i][j] = "   ";
        }
    }
}

void pattern4(string pattern[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        int k = pow(2,rows- (i+1));
        for(int j = 0; j < cols;j++)
        {
            if ( j <= (rows- (i+1))) 
            {
                pattern[i][j] = " " + to_string(k)+ " ";
                k /=2;
            }
            else pattern[i][j] = "   ";
        }
    }
}

void pattern5(string pattern[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {    
        for(int j = 0; j < cols;j++)
        {
            if ( j <= i ) 
            {
                pattern[i][j] = " "+to_string(j+1)+" ";
                if ( i == 2) pattern[i][j] = " * ";
            }
            else pattern[i][j] = "   ";
        }
    }
}

void pattern6(string pattern[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {    
        int k = 1;
        for(int j = 0; j < cols;j++)
        {
            if ( j >= i ) 
            {
                pattern[i][j] = " "+to_string(k)+" ";
                k *= 2;
            }
            else pattern[i][j] = "   ";
        }
    }
}

int main()
{
    string pattern[rows][cols];
    
    // now we will do the pattern printing using the 2D array
    pattern1(pattern);
    //display(pattern);
    
    pattern2(pattern);
    //display(pattern);
    
    pattern3(pattern);
    //display(pattern);
    
    pattern4(pattern);
    //display(pattern);
    
    pattern5(pattern);
    display(pattern);
    
    pattern6(pattern);
    //display(pattern);
    return 0;
}