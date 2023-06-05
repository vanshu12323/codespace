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

    hello();

    printf("%i", hello());

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
    int m = 4; // total number of voters
    string total[m];

    for (int i = 0 ; i < n ; i++)
    {
        total[i] = candidates[i].name;
    }

    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if (strcmp(total[i], candidates[j].name) != 0)
            {
                present_or_not = false;
            }
            else
            {
                present_or_not = true;
            }
        }
    }

    return present_or_not;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    return;
}

int hello(void)
{
    printf("%i", candidate_count);
}