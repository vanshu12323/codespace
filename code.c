#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Length: ");
    }
    while (n <= 0);

    int array[n];
    array[0] = 1;
    printf("%i\n", array[0]);

    for (int i = 1 ; i < n ; i++)
    {
        array[i] = array[i-1]*2;
        printf("%i\n", array[i]);
    }
}