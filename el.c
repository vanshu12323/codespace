#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
    int n[5] = {3,1,2,1,5};
    int m = 5;

    for (int i = 0; i < 5; i++)
    {
        if (n[i] == 1)
        {
            for (int j = 0; j < 5; j++)
            {
                n[j] = n[j];
            }
            for (int k = i + 1; k < 5; k++)
            {
                n[k - 1] = n[k];
            }
             m--;
        }
    }

    for (int i = 0; i < m ; i++)
    {
        printf("%i ", n[i]);
    }
}