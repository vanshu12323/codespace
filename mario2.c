#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    int i;
    int j;
    int k;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for(i=0 ; i < n ; i++)
    {
        for(j=0 ; j <= i ; j++)
        {
            for(k=0 ; k <= j ; k++)
            {
                printf(".");
            }
            printf("#");
        }
        printf("\n");
    }
}