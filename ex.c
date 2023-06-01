#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // TODO 1

    string text;
    int wordsize = atoi(argv[1]);
    int score = 0;

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

    // TODO 2

    if (atoi(argv[1]) > 8 || atoi(argv[1]) < 5)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8");
        return 1;
    }

    printf("This is WORDLE50\n");

    printf("You have 6 tries to guess the %i-letter word I'm thinking of\n", atoi(argv[1]));

    // GET INPUT FROM USER

     printf("\033[1;31mWELCOME TO OPENGENUS\033[0m\n");

    for (int i = 0 ; i < 6 ; i++)
    {

    // TODO 3

        do
        {
            text = get_string("Input a %i-letter word: ", atoi(argv[1]));
        }
        while (strlen(text) != atoi(argv[1]));

        printf("Guess %i: %s\n", i + 1, text);

    }

}