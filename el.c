#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
    int n[3] = {3,1,2};
    int s[3];

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (n[i] >= n[j])
            {
                s[i] = n[j];
                s[j] = n[i];
            }
        }
    }

    for (int i = 0; i < 3 ; i++)
    {
        printf("%i ", n[i]);
    }
}