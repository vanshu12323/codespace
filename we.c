#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    string name;
    int votes;
} candidate;

int main(int argc, string argv[])
{
    int n = argc - 1; // candidate_count

    if (n < 2)
    {
        printf("Usage: ./runoff [candidates...]");
    }
}