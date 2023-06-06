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

int candidate_count;
int voter_count;

candidate candidates[candidate_count];

int main(int argc, string argv[])
{
    // CLA

    int candidate_count = argc - 1; // candidate_count

    if (candidate_count < 2)
    {
        printf("Usage: ./runoff [candidates...]");
    }

    if (candidate_count > 9)
    {
        printf("Maximum number of candidates can be 9 !");
    }

    // STORING THE NAME OF CANDIDATES IN AN ARRAY

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i];
    }
}