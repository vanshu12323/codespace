#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc , string argv[])
{
    //int argv[1] = get_int("Key: ");

    string text = get_string("plaintext:  ");

    int s[strlen(text)];
    string ct[strlen(text)];

    printf("ciphertext: ");

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == ' ')
        {
            printf(" ");
        }
        s[i] = text[i];
        s[i] += argv[1];
        printf("%c", s[i]);
    }




}