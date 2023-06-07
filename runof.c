#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Usage: ./runoff [candidates...]\n");
        return 1;
    }

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates can be 9 !\n");
        return 1;
    }

    // STORING THE NAME OF CANDIDATES IN AN ARRAY
    // INITIALIZING NO. OF VOTES = 0
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Number of voters
    voter_count = get_int("Number of voters: ");

    // UPDATING NO. OF VOTES AND RANK OF EACH CANDIDATE
    string vote_name[voter_count][candidate_count];

    for (int i = 0; i < voter_count; i++)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            vote_name[i][k] = get_string("Rank %i: ", k + 1);

            // CHECKING FOR ANY INVALID VOTES
            for (int j = 0; j < candidate_count; j++)
            {
                if (strcmp(vote_name[i][k], candidates[j].name) == 0)
                {
                    candidates[j].votes += candidate_count - k;
                    break;
                }
                else if (j == candidate_count - 1 && strcmp(vote_name[i][k], candidates[j].name) != 0)
                {
                    printf("Invalid vote.\n");
                    break;
                }
            }
        }
        printf("\n");
    }

    // SORTING THE CANDIDATES BASED ON THE NO. OF VOTES
    int sorted_votes[candidate_count];
    string voted_to[candidate_count];

    for (int i = 0; i < argc - 1; i++)
    {
        sorted_votes[i] = candidates[i].votes;
        voted_to[i] = candidates[i].name;
    }

    for (int i = 0; i < argc - 1; i++)
    {
        for (int j = 0; j < argc - 1; j++)
        {
            if (sorted_votes[i] <= sorted_votes[j])
            {
                sorted_votes[i] = candidates[j].votes;
                sorted_votes[j] = candidates[i].votes;
                candidates[i].votes = sorted_votes[i];
                candidates[j].votes = sorted_votes[j];

                voted_to[i] = candidates[j].name;
                voted_to[j] = candidates[i].name;
                candidates[i].name = voted_to[i];
                candidates[j].name = voted_to[j];
            }
        }
    }

    // PRINTING THE WIINER
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == candidates[candidate_count - 1].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    // for (int i = 0; i < candidate_count; i++)
    // {
    //     printf("%s got %i votes.\n", candidates[i].name, candidates[i].votes);
    // }
}