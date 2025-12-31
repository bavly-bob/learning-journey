// Pig Latin translator
// codewars.com/kata/520b9d2ad5c005041100000f
// instructions: Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.


// optimized version of pig_it function
#include <string>
#include <cctype>
using namespace std;

string pig_it(string str)
{
    string result;
    int n = str.size();

    for (int i = 0; i < n; )
    {
        if (isalpha(str[i])) // start of a word
        {
            char first = str[i];
            i++;

            // copy the rest of the word
            while (i < n && isalpha(str[i]))
            {
                result += str[i];
                i++;
            }

            result += first;
            result += "ay";
        }
        else
        {
            // punctuation or space
            result += str[i];
            i++;
        }
    }

    return result;
}
