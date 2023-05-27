#include <cs50.h>
#include <stdio.h>
#include <math.h>

float average(int numbers[]);

int main(void)
{
    int scores[3];
    for(int i = 0 ; i < 3 ; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f" , average(scores));
}

float average(int numbers[])
{
    
}