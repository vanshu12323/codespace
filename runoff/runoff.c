#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;
string voted_for[MAX_VOTERS][MAX_CANDIDATES];

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
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

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            voted_for[i][j] = get_string("Rank %i: ", j + 1);
            preferences[i][j] = j;

            // Record vote, unless it's invalid
            if (!vote(i, j, voted_for[i][j]))
            {
                printf("Invalid vote.\n");
            }
        }

        printf("\n");
    }

    //--------------------------------------------------------------------------

    // Keep holding runoffs until winner exists
    // while (true)
    // {
    //     // Calculate votes given remaining candidates
    //     tabulate();

    //     // Check if election has been won
    //     bool won = print_winner();
    //     if (won)
    //     {
    //         break;
    //     }

    //     // Eliminate last-place candidates
    //     int min = find_min();
    //     bool tie = is_tie(min);

    //     // If tie, everyone wins
    //     if (tie)
    //     {
    //         for (int i = 0; i < candidate_count; i++)
    //         {
    //             if (!candidates[i].eliminated)
    //             {
    //                 printf("%s\n", candidates[i].name);
    //             }
    //         }
    //         break;
    //     }

        // Eliminate anyone with minimum number of votes
    //     eliminate(min);

    //     // Reset vote counts back to zero
    //     for (int i = 0; i < candidate_count; i++)
    //     {
    //         candidates[i].votes = 0;
    //     }
    // }

    //------------------------------------------------------------------

    tabulate();
    for(int i = 0; i < candidate_count; i++)
    {
        printf("%s got %i votes.\n", candidates[i].name, candidates[i].votes);
    }

    bool won = print_winner();
    printf("WON: %d\n", won);

    int min = find_min();
    printf("MIN. VOTES: %i\n", min);

    bool tie = is_tie(min);
    printf("TIE: %d\n", tie);

    return 0;
}




//*****************************************************************************



// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    bool present;

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (strcmp(name, candidates[j].name) == 0)
            {
                present = true;
                break;
            }
            else if (j == candidate_count - 1 && strcmp(name, candidates[j].name) != 0)
            {
                present = false;
                break;
            }
        }
    }

    return present;
}




//---------------------------------------------------------------------


// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (strcmp(voted_for[i][0], candidates[j].name) == 0)
            {
                candidates[j].votes += 1;
                break;
            }
        }
    }
}





//----------------------------------------------------------------------



// Print the winner of the election, if there is one
bool print_winner(void)
{
    int max_votes = voter_count;
    bool won = false;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes / 2.0)
        {
            printf("WINNER: %s\n", candidates[i].name);
            won = true;
        }
    }

    printf("REQ. VOTES TO WIN: %f\n", round(max_votes/2.0));

    return won;
}




//--------------------------------------------------------------------------





// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int sorting_votes[candidate_count];
    string sorting_name[candidate_count];
    for (int  i = 0; i < candidate_count; i++)
    {
        sorting_votes[i] = candidates[i].votes;
        sorting_name[i] = candidates[i].name;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int  j= 0; j < candidate_count; j++)
        {
            if (candidates[i].votes > candidates[j].votes)
            {
                sorting_votes[i] = candidates[j].votes;
                sorting_votes[j] = candidates[i].votes;
                candidates[i].votes = sorting_votes[i];
                candidates[j].votes = sorting_votes[j];

                sorting_name[i] = candidates[j].name;
                sorting_name[j] = candidates[i].name;
                candidates[i].name = sorting_name[i];
                candidates[j].name = sorting_name[j];
            }
        }
    }

    return sorting_votes[candidate_count];
}





//-------------------------------------------------------------------------






// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    bool tie = false;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[i].votes == candidates[j].votes == min)
            {
                tie = true;
            }
        }
    }

    return tie;
}





//-------------------------------------------------------------------------






// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    return;
}