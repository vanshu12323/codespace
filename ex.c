#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./wordle wordsize");
        return 1;
    }

    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./wordle wordsize");
            return 1;
        }
    }
}