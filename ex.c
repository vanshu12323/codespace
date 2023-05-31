#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int key = get_int("Key: ");

    string text = get_string("plaintext:  ");

    int s[strlen(text)];
    string ct[strlen(text)];

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == ' ')
        {
            printf(" ");
        }
        s[i] = text[i];
        s[i] += key;
        printf("%c" , s[i] );
    }

    //printf("ciphertext: %c");


}