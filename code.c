#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int numbers[] = {20, 500, 15, 5, 100, 1, 50};

    int n = get_int("Numbers: ");

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not found\n");
        return 1;
}