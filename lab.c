#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    int m;
    int t = 0;

    do
    {
        n = get_int("Starting population : ");
    }
    while(n < 9);

    do
    {
        m = get_int("Ending population : ");
    }
    while(m < n);

    while(n < m)
       { n = n + n/3 - n/4;
         t++;
       }

    printf("Years: %d", t);

}