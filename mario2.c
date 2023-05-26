#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    int i=0;
    int j=0;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for(i=0 ; i >= j ; i++)
    {
        for(j=0 ; j < n ; j++)
        {
            printf(".");
        }
        printf("#");
        printf("\n");
    }
}