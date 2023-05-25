#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    int n = 0;
    int m = 0;

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

    float t =  ;

    printf("Years: %i", (int)round(t));


}