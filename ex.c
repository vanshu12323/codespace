#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string text;

    // CHECKING THE LENGTH OF CLA

    if (argc != 2)
    {
        printf("Usage: ./wordle wordsize");
        return 1;
    }

    // CHECKING IF THE INPUT IN CLA IS ONLY A NUMBER BETWEEN 5 TO 8

    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./wordle wordsize");
            return 1;
        }
    }

    if (atoi(argv[1]) > 8 || atoi(argv[1]) < 5)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8");
        return 1;
    }

    printf("This is WORDLE50\n");

    printf("You have 6 tries to guess the %i-letter word I'm thinking of\n", atoi(argv[1]));

    // GET INPUT FROM USER

    for (int i = 0 ; i < 6 ; i++)
    {
        do
        {
            text = get_string("Input a %i-letter word: ", atoi(argv[1]));
        }
        while (strlen(text) != atoi(argv[1]));

        printf("Guess %i: %s", i + 1, text);

    }
}