#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    int i;
    int j;
    int k;
    int l;
    int m;

    //GET INPUT

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //LOOP

    for (i = 1 ; i <= n ; i++)
    {
        for (k = i + 1 ; k <= n ; k++)
        {
            printf(" ");
        }
        for (j = 0 ; j < i ; j++)
        {
            printf("#");
        }
        printf("  ");
        for (j = 0 ; j < i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}