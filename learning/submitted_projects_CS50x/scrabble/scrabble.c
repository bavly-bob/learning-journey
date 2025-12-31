#include <cs50.h>
#include <ctype.h> // for tolower()
#include <stdio.h>

// Function to get scrabble score of a word
int count_points(char *s)
{
    // Scrabble points lookup table
    int points_table[26] = {
        1,  // A
        3,  // B
        3,  // C
        2,  // D
        1,  // E
        4,  // F
        2,  // G
        4,  // H
        1,  // I
        8,  // J
        5,  // K
        1,  // L
        3,  // M
        1,  // N
        1,  // O
        3,  // P
        10, // Q
        1,  // R
        1,  // S
        1,  // T
        1,  // U
        4,  // V
        4,  // W
        8,  // X
        4,  // Y
        10  // Z
    };

    int points = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int x = tolower(s[i]);
        if (x >= 'a' && x <= 'z')
        {
            points += points_table[x - 'a'];
        }
    }
    return points;
}

int main()
{
    char *player1 = get_string("player1: ");
    char *player2 = get_string("player2: ");
    int player1_points = count_points(player1);
    int player2_points = count_points(player2);

    if (player1_points > player2_points)
    {
        printf("Player 1 wins!");
    }
    else if (player1_points < player2_points)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("tie!");
    }
}
