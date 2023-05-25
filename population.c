#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    int n = 0;
    int m = 0;

    do
    {
        n = get_int("Start population : ");
    }
    while(n < 9);

    do
    {
        m = get_int("Ending population : ");
    }
    while(m < n);

    float t = ((12*(float)m)/(float)n - 12) ;

    printf("Population will grow from %i to %i in %i years .\n" , n , m , (int)round(t));


}