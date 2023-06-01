#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("Usage: ./substitution key");
            return 1;
        }

        else if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
    }
}