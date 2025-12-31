#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Text: ");

    // define all varibles
    int word_count = 1;
    int letters_count = 0;
    int sentence_count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int x = tolower(s[i]);
        if (x >= 'a' && x <= 'z')
        {
            letters_count++;
        }
        else if (s[i] == ' ')
        {
            word_count++;
        }
        else if (s[i] == '!' || s[i] == '?' || s[i] == '.')
        {
            sentence_count++;
        }
    }

    // Coleman–Liau formula
    float L = ((float) letters_count / word_count) * 100;
    float S = ((float) sentence_count / word_count) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
