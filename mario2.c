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

    for(i=0 ; i < n ; i += 3)
    {
        for(j=0 ; j <= n ; j+=2)
        {
            printf(".");
        }
        printf("#");
        printf("\n");
    }
}