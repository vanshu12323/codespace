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
int voter_count;

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

    voter_count = get_int("Number of voters: ");

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
    bool present_or_not;
    int n = candidate_count;
    int m = voter_count; // total number of voters
    string total_votes[m];

    for (int i = 0 ; i < n ; i++)
    {
        total_votes[i] = candidates[i].name;
        candidates[i].votes = 0;
    }

    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if (strcmp(name, candidates[j].name) == 0)
            {
                present_or_not = true;
                candidates[j].votes += 1;
                break;
            }
            else if (j == n - 1 && strcmp(name, candidates[j].name) != 0)
            {
                present_or_not = false;
            }
        }
    }

    return present_or_not;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int n = candidate_count;
    int sorted[n];
    string names[n];

    for (int i = 0; i < n; i++)
    {
        sorted[i] = candidates[i].votes;
        names[i] = candidates[i].name;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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

    for (int i = 0; i < n; i++)
    {
        if (candidates[i].votes == candidates[n - 1].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
