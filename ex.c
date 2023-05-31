#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");

    int s[strlen(text)];
    string ct[strlen(text)];

    int key = get_int("Key: ");

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        s[i] = text[i];
        s[i] += key;
        printf("%i " , s[i]);
        printf("%c " , s[i] );
    }


}