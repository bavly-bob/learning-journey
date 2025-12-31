#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSubsequence(const string& word, const string& sub)
{
    int pos = 0;

    for (char c : sub)
    {
        pos = word.find(c, pos);
        if (pos == string::npos)
            return false;
        pos++; // move forward
    }
    return true;
}

int main()
{
    string word;
    cin >> word;

    int n;
    cin >> n;

    vector<string> sub_word(n);
    for (int i = 0; i < n; i++)
        cin >> sub_word[i];

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (word.find(sub_word[i]) != string::npos || isSubsequence(word, sub_word[i]))
        {
            count++;
        }
    }

    cout << count << endl;
}
