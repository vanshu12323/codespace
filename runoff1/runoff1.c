#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

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
int minimum;

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

    string voted[voter_count][candidate_count];
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            voted[i][j] = voted_for[i][j];
        }
    }

    // tabulate();

    // for(int i = 0; i < candidate_count; i++)
    // {
    //     printf("%s got %i votes.\n", candidates[i].name, candidates[i].votes);
    // }


    // bool won = print_winner();
    // printf("WON : %d\n", won);

    // minimum = find_min();
    // printf("MIN: %i\n", minimum);

    // bool tie_or_not = is_tie(minimum);
    // printf("TIE: %d\n", tie_or_not);

    // eliminate(minimum);

    // for (int i = 0; i < candidate_count; i++)
    // {
    //     candidates[i].votes = 0;
    // }


    // tabulate();

    // for(int i = 0; i < candidate_count; i++)
    // {
    //     printf("%s got %i votes.\n", candidates[i].name, candidates[i].votes);
    // }

    // won = print_winner();
    // printf("WON : %d\n", won);

    // minimum = find_min();
    // printf("MIN: %i\n", minimum);

    // tie_or_not = is_tie(minimum);
    // printf("TIE: %d\n", tie_or_not);


    while(true)
    {
        tabulate();
    //     for(int i = 0; i < candidate_count; i++)
    // {
    //     printf("%s got %i votes.\n", candidates[i].name, candidates[i].votes);
    // }

        bool won = print_winner();
        //printf("WON : %d\n", won);

        if(won)
        {
            break;
        }

        minimum = find_min();
        printf("MIN: %i\n", minimum);

        bool tie_or_not = is_tie(minimum);
        printf("TIE: %d\n", tie_or_not);

        if(tie_or_not)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }

            break;
        }

        eliminate(minimum);

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;

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
            for (int k = 0; k < candidate_count; k++)
            {
                if (strcmp(voted_for[i][j], candidates[k].name) == 0 )  // && candidates[i].eliminated == true)
                {
                    candidates[k].votes += candidate_count - j;
                    break;
                }
            }
        }
    }
}

















// WINNER OR NOT
bool print_winner(void)
{
    int total_votes;
    int nn = candidate_count;
    bool won = false;

    for (int i = 1; i < candidate_count; i++)
    {
        nn = nn * i;
    }

    total_votes = nn * voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= total_votes / 2.0 )
        {

            // if (candidates[i].votes > find_min())
            // {
               // printf("WINNER = %s\n", candidates[i].name);
                //break;
            // }
            // else if (i == candidate_count - 1 && candidates[candidate_count - 1].votes >= find_min())
            // {
            //     printf("WINNER = %s\n", candidates[i].name);
            //     //won = true;
            // }

// -----------

            for (int j = i + 1; j < candidate_count; j++)
            {
                if (candidates[j].votes > candidates[i].votes)
                {
                    printf("%s\n", candidates[j].name);
                    break;
                }
                else
                {
                    printf("%s\n", candidates[i].name);
                    break;
                }
            }
// ------------
            won = true;
            break;
        }
        // else if (candidates[i].votes == total_votes / 2.0)
        // {
        //   printf("%s\n", candidates[i].name);
        //   won = true;
        //   break;
        // }
    }

    //printf("VOTES REQ. TO WIN = %f\n", total_votes/2.0);

    return won;
}



















// FINDING MINIMUM NUMBER OF VOTES BEFORE/AFTER ELIMINATION
int find_min(void)
{
    int n = candidate_count;
    int sorted[n];
    string names[n];
    int m = voter_count;

    // PREPARING TO SORT

    for (int i = 0; i < n; i++)
    {
        sorted[i] = candidates[i].votes;
    }

    for (int i = 0; i < n; i++)
    {
        names[i] = candidates[i].name;
    }

    // SORTING THE CANDIDATES BASED ON THEIR NUMBER OF VOTES

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

    return sorted[0];
}
















// IS A TIE OR NOT
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

















// elimination
void eliminate(int min)
{
    
    int new_candidate_count = candidate_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
            for (int j = 0; j < i; j++)
            {
                candidates[j].votes = candidates[j].votes;
                candidates[j].name = candidates[j].name;
            }
            for (int k = i + 1; k < candidate_count; k++)
            {
                candidates[k - 1].votes = candidates[k].votes;
                candidates[k - 1].name = candidates[k].name;
            }

            new_candidate_count--;
        }
    }

    candidate_count = new_candidate_count;

    // printf("after elimination candidates left: ");
    // for (int i = 0; i < new_candidate_count; i++)
    // {
    //     printf("%s ", candidates[i].name);
    // }
    // printf("\n");

    //printf("%i candidates left after elimination\n", new_candidate_count);
    return;
}