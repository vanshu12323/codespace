#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    float n = 0;
    float m = 0;

    do
    {
        n = get_float("Starting population : ");
    }
    while(n < 9);

    do
    {
        m = get_float("Ending population : ");
    }
    while(m < n);

    float t = (log(m/n))/0.08004270767;

    printf("Years: %i", (int)round(t));


}