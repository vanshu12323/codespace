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

    for (i=0 ; i <= n ; i++)
    {
        for (k= i+1 ; k <= n ; k++)
            {
                printf(" ");
            }

        for (j=0 ; j < i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}