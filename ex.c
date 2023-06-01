#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int aoi

    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else if (argv[1] < 0)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else
    {
        string text = get_string("plaintext:  ");
    }

    int key = get_int("Key: ");
   // string text = get_string("plaintext:  ");
    int m[strlen(text)];

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (isupper(text[i]))
        {
            m[i] = text[i] - 65;
        }
        else if(islower(text[i]))
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
            m[i] = ((m[i] + key) % 26) + 65;
            printf("%c" , m[i]);
        }
        else if(islower(text[i]))
        {
            m[i] = ((m[i] + key) % 26) + 97;
            printf("%c" , m[i]);
        }
        else
        {
            printf("%c" , text[i]);
        }
    }

    return 0;
}