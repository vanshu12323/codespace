#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string text;

    //COMMAND LINE ARGUMENT , PROMPTING THE USER TO ENTER ONLY POSITIVE INTEGER

    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if (argv[1][i] != isdigit(atoi(&argv[1][i])))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    if (atoi(argv[1]) < 0)
    {
        printf("ERROR! ENTER A VALID KEY!");
        return 1;
    }
    else
    {
        text = get_string("plaintext:  ");
    }

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
        if (text[i] == ' ')
        {
            printf(" ");
        }
        else if (isupper(text[i]))
        {
            m[i] = ((m[i] + atoi(argv[1])) % 26) + 65;
            printf("%c", m[i]);
        }
        else if (islower(text[i]))
        {
            m[i] = ((m[i] + atoi(argv[1])) % 26) + 97;
            printf("%c", m[i]);
        }
        else
        {
            printf("%c" , text[i]);
        }
    }

    printf("\n");

    return 0;
}