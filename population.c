#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // DECLARE STARTING AND ENDING POPULATION

    float n;
    float m;

    do
    {
        n = get_float("Starting population : ");
    }
    while (n < 9);

    do
    {
        m = get_float("Ending population : ");
    }
    while (m < n);

    //CALCULATE TIME IN YEARS

    float t = (log(m / n)) / 0.08004270767;

    //FINAL ANSWER

    printf("Years: %i", (int)round(t));


}