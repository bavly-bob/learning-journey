#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if all characters in argv[1] are digits
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be a number.\n");
            return 1;
        }
    }

    int y = atoi(argv[1]) % 26;

    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; plain[i] != '\0'; i++)
    {
        if (isupper(plain[i]))
        {
            int a = (plain[i] - 'A' + y) % 26 + 'A';
            printf("%c", a);
        }
        else if (islower(plain[i]))
        {
            int b = (plain[i] - 'a' + y) % 26 + 'a';
            printf("%c", b);
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}
