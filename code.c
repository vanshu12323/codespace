#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int array[5];
    array[0] = 1;
    printf("%i\n", array[0]);

    for (int i = 1 ; i <= 4 ; i++)
    {
        printf("%i\n", array[i-1]*2);
    }
}