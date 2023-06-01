#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string text;

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

    text = get_string("plaintext:  ");


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

    printf("ciphertext: ");

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == ' ')
        {
            printf(" ");
        }
        else if (isupper(text[i]))
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