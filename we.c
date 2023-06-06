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
    // INITIALIZING NO. OF VOTES = 0
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i];
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

            // CHECKING FOR ANYN INVALID VOTES
            for (int j = 0; j < candidate_count; j++)
            {
                if (strcmp(vote_name[i][k], candidates[j].name) == 0)
                {
                    candidates[j].votes += 1;
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

    for (int i = 0; i < candidate_count; i++)
    {
        printf("%s got a total of %i votes.", candidates[i].name, candidates[i].votes);
    }
}