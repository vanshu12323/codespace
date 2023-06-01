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

    print

    printf("ciphertext: ");

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        m[i] = (m[i] + key) % 26;
        printf("%c" , m[i]);
    }
}