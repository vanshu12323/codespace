#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int key = get_int("Key: ");
    string text = get_string("plaintext:  ");
    int m[26];

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

    //printf("%i %i %i" , m[0] , m[1] , m[2]);

    printf("ciphertext: ");

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == ' ')
        {
            printf(" ");
        }
        else if (isupper(text[i]))
        {
            text[i] = ((m[i] + key) % 26) + 65;
            printf("%c" , text[i]);
        }
        else if(islower(text[i]))
        {
            text[i] = ((m[i] + key) % 26) + 97;
            printf("%c" , text[i]);
        }
        else
        {
            printf("%c" , text[i]);
        }
    }
}