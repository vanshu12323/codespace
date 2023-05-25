#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    float n;
    float m;

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

    double r = log(13/12);



    float t = (log(m/n)) / r;

    printf("%.20f\n" , r);

    printf("Years: %i", (int)round(t));


}