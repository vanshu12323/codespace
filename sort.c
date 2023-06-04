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

    for (int i = 0 ; i < 3 ; i++)
    {
        if (n[i] > n[i+1])
        {
            n[i+1] = n[i];
            n[i] = n[i+1];

            for (int j = 0 ; j < 7 ; j++)
            {
                if (n[i] > n[i+1])
                {
                    n[i+1] = n[i];
                    n[i] = n[i+1];
                }
            }
        }
    }
}