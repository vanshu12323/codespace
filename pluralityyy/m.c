#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int m = candidate_count;
    int sorted[m];
    string names[m];

    for (int i = 0 ; i < m ; i++)
    {
        sorted[i] = candidates[i].votes;
        names[i] = candidates[i].name;
    }

    for (int i = 0 ; i <  ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                if (sorted[i] <= sorted[j])
                {
                    sorted[i] = candidates[j].votes;
                    sorted[j] = candidates[i].votes;
                    candidates[i].votes = sorted[i];
                    candidates[j].votes = sorted[j];

                    names[i] = candidates[j].name;
                    names[j] = candidates[i].name;
                    candidates[i].name = names[i];
                    candidates[j].name = names[j];
                }
            }

        }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int n = candidate_count;
    for (int i = 0 ; i < n ; i++)
    {
        if (candidates[i].votes == candidates[n].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}