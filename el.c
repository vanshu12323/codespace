#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
    int n[4] = {1,2,3,4};

    for (int i = 0; i < 4; i++)
    {
        if (n[i] == 3)
        {
            for (int j = 0; j < i; j++)
            {
                n[j] = n[j];
            }
            for (int k = i + 1; k < 4; k++)
            {
                n[k - 1] = n[k];
            }
        }
    }

    for (int i = 0; i < 4 ; i++)
    {
        printf("%i ", n[i]);
    }
}