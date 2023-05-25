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

    double r;
    double num = 13/12;

    r = log(num);

    float t = (log(m/n)) / r;

    printf("%f and %f\n", r , num);

    printf("Years: %i", (int)round(t));


}