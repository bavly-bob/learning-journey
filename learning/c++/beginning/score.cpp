#include <iostream>

using namespace std;

int main() {
    int x=3;
    int score[x];
    int lowest_score = 101;

    for (int i = 0; i < x; i++) 
    {
        cout << "Enter your score (0-100): ";
        cin >> score[i];
        if (score[i] < 0 || score[i] > 100) 
        {
            cout << "Invalid score. Please enter a score between 0 and 100." << endl;
            i--; // Decrement i to repeat this iteration
            continue;
        }
        else if (lowest_score > score[i]) 
        {
            lowest_score = score[i];
        }
    }
    cout << "Lowest score is: " << lowest_score << endl;

    
    return 0;
}