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
int ranks[MAX_VOTERS][MAX_CANDIDATES];
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
            ranks[i][j] = j + 1;
            if (!vote(i, j, voted_for[i][j]))
            {
                printf("Invalid vote.\n");
            }
        }

        printf("\n");
    }

    for (int )
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














// UPDATE NUMBER OF VOTES
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {

        }
    }
}