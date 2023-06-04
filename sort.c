#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <search.h>

int main(void)
{
    int sorted[7];
    int n[7] = {4, 5, 9, 2, 3, 0, 1};

    for (int i = 0 ; i < 7 ; i++)
    {
        sorted[i] = n[i];
    }

    sorted[5] = n[4];
    sorted[4] = n[5];

    for (int i = 0 ; i < 7 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (n[i] >= n[j])
            {
                sorted[i] = n[j];
                break;
            }
        }
    }

    for (int i = 0 ; i < 7 ; i++)
    {
        printf("%i ", sorted[i]);
    }
}