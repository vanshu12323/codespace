#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <search.h>

int main(void)
{
    int s[7];
    int n[7];

    for (int i = 0 ; i < 7 ; i++)
    {
        n[i] = get_int("Enter a number: ");
    }

    for (int i = 0 ; i < 7 ; i++)
    {
        s[i] = n[i];
    }

    //sorted[5] = n[4];
    //sorted[4] = n[5];

    for (int i = 0 ; i < 7 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (s[i] <= s[j])
            {
                s[i] = n[j];
                s[j] = n[i];
                n[i] = s[i];
                n[j] = s[j];
            }
        }
    }

    printf("Sorted: ");

    for (int i = 0 ; i < 7 ; i++)
    {
        printf("%i ", s[i]);
    }
}