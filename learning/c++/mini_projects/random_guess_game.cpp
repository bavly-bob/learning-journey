// random_guess_game.cpp
// A simple random number guessing game with different difficulty levels
// The user selects a difficulty level which determines the range of the random number
// and the number of allowed attempts to guess the number.
// The user inputs guesses and receives feedback until they guess correctly or run out of attempts.

#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

bool guess(int user_number, int number ,int level, int &user_tries);

int main()
{
    int level;
    cout << "what level do you want to play?" << endl;
    cout << "1. easy (number between 1-100 and unlimited tries)  " << endl;
    cout << "2. medium (number between 1-200 and 10 tries)" << endl;
    cout << "3. hard (number between 1-300 and 7 tries)" << endl;
    cin >> level;
    
    srand(time(0));          // seed random generator
    int number = (rand() % (100*level)) + 1 , user_number ,user_tries = 0;
    
    cout << "enter a random number between 1 and "<<100*level<<": " << endl;
    cin >> user_number;
    user_tries++;
    
    bool guessing_result = guess(user_number, number, level, user_tries);
    if (guessing_result)
    {
        cout << "congratulations! you guessed it!" << endl;
        cout << "it took you " << user_tries << " tries to guess the number " << number << endl;
    }
    else
    {
        cout << "sorry, you lost! the number was " << number << endl;
    }
    return 0;
}

bool guess(int user_number, int number, int level, int &user_tries)
{
    int tries[]= {0, 1000, 10, 7};
    while (user_number != number && user_tries < tries[level])
    {          
        if (user_number > number)
            cout << "too high" << endl;
        else
            cout << "too low" << endl;
        cout << "try again: " ;
        cin >> user_number;
        user_tries++;
    }
    if (user_number != number && user_tries == tries[level])
        return false;
    return true;
}