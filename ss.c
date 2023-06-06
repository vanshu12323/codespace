#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

int voter_count;
int candidate_count;
string voted_for[MAX_VOTERS][MAX_CANDIDATES];

candidate candidates[MAX_CANDIDATES];

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // CLA
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // MAX NO. OF CANDIDATES
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // MAX NO. OF VOTERS
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            voted_for[i][j] = get_string("Rank %i: ", j + 1);

            // UPDATING SCORES OF CANDIDATES
            for (int k = 0; k < candidate_count; k++)
            {
                if (strcmp(voted_for[i][j], candidates[k].name) == 0)
                {
                    candidates[k].votes += candidate_count - j;
                    break;
                }
            }
            if (!vote(i, j, voted_for[i][j]))
            {
                printf("Invalid vote.\n");
                // break;
            }
        }
        printf("\n");
    }

    for (int i = 0; i < candidate_count; i++)
    {
        printf("%s got %i votes.\n", candidates[i].name, candidates[i].votes);
    }

    bool won = print_winner();
    printf("won: %d\n", won);

    while (true)
    {
        tabulate();

        // PRINTING WINNER IF THERE IS ONE
        if (won)
        {
            int n = candidate_count;

            for (int i = 0; i < candidate_count; i++)
            {
                n = n * (i + 1);
            }

            int total_votes = voter_count * n;

            for (int i = 0; i < candidate_count; i++)
            {
                if (candidates[i].votes >= (int)total_votes / 2)
                {
                    printf("%s", candidates[i].name);
                }
            }
        }
    }


}










// INVALID VOTE
bool vote(int voter, int rank, string name)
{
    bool present_or_not;

    for(int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            present_or_not = true;
            break;
        }
        else if (i == candidate_count - 1 && strcmp(name, candidates[i].name) != 0)
        {
            present_or_not = false;
        }
    }
    return present_or_not;
}






















// UPDATING SCORES OF CANDIDATES
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            for (int k = 0; k < candidate_count; k++)
            {
                if (strcmp(voted_for[i][j], candidates[k].name) == 0)
                {
                    candidates[k].votes += candidate_count - j;
                    break;
                }
            }
        }
    }
}











// CHECKING IF THERE IS A WINNER OR NOT
bool print_winner(void)
{
    bool winner = false;
    int n = candidate_count;
    for (int i = 0; i < candidate_count; i++)
    {
        n = n * (i + 1);
    }
    int total_votes = voter_count * n;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= (float)total_votes / 2.0)
        {
            winner = true;
        }
    }

    return winner;
}


















// FINDING MINIMUM NUMBER OF VOTES BEFORE/AFTER ELIMINATION
int find_min(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        
    }
}