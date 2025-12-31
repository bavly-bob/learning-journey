#include <iostream>
using namespace std;

bool 

int main()
{
    int grid[9][9];
    cout << "Enter Sudoku (use 0 for empty):\n";
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {

            }
        }
    
    
    cout << "Solved Sudoku:\n";
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
}
