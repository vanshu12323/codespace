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
        for (int j = i + 1 ; j < 7 ; i++)
        {
            if (n[i] > n[j])
            {
                sorted[i] = n[j];
                break;
            }
        }
    }

    printf("Sorted:\n");

    for (int i = 0 ; i < 7 ; i++)
    {
        printf("%i\n", sorted[i]);
    }
}