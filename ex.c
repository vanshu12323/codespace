#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("plaintext:  ");
    int m[strlen(text)];

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (isupper(text[i]))
        {
            m[i] = text[i];
            printf("%i %c" , m , m);
        }
        else if(islower(text[i]))
        {
            m[i] = text[i];
        }
    }
}