#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string text;

    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    // CHECKING IF THE INPUT IN CLA IS 26 LETTERS

    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("Usage: ./substitution key");
            return 1;
        }

        else if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
    }

    // CHECKING IF ANY LETTER IS REPEATED

    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        for (int j = 0 ; j < strlen(argv[1]) ; j++)
        {
            if (argv[1][i] == argv[1][j] && i != j)
            {
                printf("ERROR! NO DUPLICATES ALLOWED!");
                return 1;
            }
        }
    }

    text = get_string("plaintext:  ");

    // CONVERTING PLAINTEXT TO NUMBER

    int m[strlen(text)];

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (isupper(text[i]))
        {
            m[i] = text[i] - 65;
        }
        else if (islower(text[i]))
        {
            m[i] = text[i] - 97;
        }
    }

    // CONVERTING PLAINTEXT TO CIPHERTEXT

    printf("ciphertext: ");

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", toupper(argv[1][m[i]]));
        }
        else if (islower(text[i]))
        {
            printf("%c", tolower(argv[1][m[i]]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");

    return 0;
}