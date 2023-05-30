#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

    // GET INPUT

    string s = get_string("Message: ");
    int ascii[strlen(s)];
    int remainder[8 * strlen(s)];

    // CONVERT INPUT TO NUMBER AND THEN TO BINARY(REVERSED)

    for (int i = 0 ; i < strlen(s) ; i++)
    {
        ascii[i] = s[i];

        for (int j = 8 * i  ; j <= 8 * i + 7 ; j++, ascii[i] /= 2)
        {
            remainder[j] = ascii[i] % 2;
        }
    }

    // CORRECTING THE ORDER OF NUMBER IN BINARY

    for (int i = 0 ; i < strlen(s) ; i++)
    {
        for (int j = 8 * i + 7; j >= 8 * i ; j--)
        {
        }
    }


    for (int i = 0 ; i < strlen(s) ; i++)
    {
        for (int j = 8 * i + 7 ; j >= 8 * i ; j--)
        {
            if (remainder[j] == 1)
            {
                printf("🟡");
            }
            else if (remainder[j] == 0)
            {
                printf("⚫");
            }
        }
        printf("\n");
    }
}