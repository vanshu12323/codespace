#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    float n = 0;
    float m = 0;

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

    //float t = (log((float)m/(float)n))/0.0800427077;
    float t = (log(m/n))/log(13/12);

    printf("Years: %i", (int)round(t));


}