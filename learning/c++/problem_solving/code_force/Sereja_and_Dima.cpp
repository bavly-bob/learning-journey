#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    
    vector<int> cards(t);
    for (int i = 0; i < t; i++)
        cin >> cards[i];

    int l = 0, r = t - 1;
    int sereja = 0, dima = 0;
    bool turn = true;

    while (l <= r)
    {
        int picked;
        if (cards[l] >= cards[r])
            picked = cards[l++];
        else
            picked = cards[r--];

        if (turn) sereja += picked;
        else dima += picked;

        turn = !turn;
    }

    cout << sereja << " " << dima << endl;
}