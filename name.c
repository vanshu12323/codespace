#include <cs50.h>
#include <stdio.h>
#include <math.h>

float average(int numbers[]);

int main(void)
{
    
}

float average(int numbers[])
{
    int score[];
    for(int i = 0 ; i < 3 ; i++)
    {
        score[i] = get_int("Score: ");
    }
    printf("Average: %f" , score[i]/3.0);
}