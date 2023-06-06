#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// MAX. NO. OF CANDIDATES
#define MAX 9

typedef struct
{
    string name;
    int votes;
} candidate;

int candidate_count;
int voter_count;

candidate candidates[MAX];

int main(int argc, string argv[])
{
    // CLA
    candidate_count = argc - 1; // candidate_count

    if (candidate_count < 2)
    {
        printf("Usage: ./runoff [candidates...]");
    }

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates can be 9 !");
    }

    // STORING THE NAME OF CANDIDATES IN AN ARRAY
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i];
    }

    // Number of voters
    voter_count = get_int("Number of voters: ");

    // UPDATING NO. OF VOTES AND RANK OF EACH CANDIDATE
    string votes[voter_count][candidate_count];

    for (int i = 0; i < voter_count; i++)
    {
        votes[i] = get_string("Vote: ");

        for (int j = 0; j < candidate_count; j++)
        {
            if (strcmp(votes[i], candidates[j].name) == 0)
            {
                candidates[j].vote += 1;
                break;
            }
            else if (j == argc - 2 && strcmp(votes[i], candidates[j].name) != 0)
            {
                printf("Invalid vote.\n");
            }
        }
    }
}