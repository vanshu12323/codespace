#include <cs50.h>
#include <stdio.h>
#include <math.h>

const int N = 3;

float average(int numbers[]);

int main(void)
{
    int scores[N];
    for(int i = 0 ; i < N ; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f" , average(scores));
}

float average(int number[])
{
    int sum = 0;
    for(int n = 0 ; n < N ; n++)
    {
        sum += number[n];
    }
    return sum / (float) N ;
}