#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES]; // MAX_VOTERS JITNE ELEMENTS OR UN ELEMNETS M MAX_CANDIDATES KI JGH LIKE ->
// int n[2][3] = {{1,2,3} , {5,6,7}} // EK ARRAY M 2 ELEMENTS OR VO ELEMENTS BHI EK ARRAY HE H 3 ELEMENTS KI !

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
string namee[MAX_VOTERS][MAX_CANDIDATES];

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

    // string name[voter_count][candidate_count];
    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            namee[i][j] = get_string("Rank %i: ", j + 1);

            for (int k = 0; k < candidate_count; k++)
            {
                if (strcmp(namee[i][j], candidates[k].name) == 0)
                {
                    candidates[k].votes += candidate_count - j;
                    break;
                }
                // Record vote, unless it's invalid
                else if (!vote(i, j, namee[i][j]))
                {
                    printf("Invalid vote.\n");
                    // return 4;
                }
            }
        }
        printf("\n");
    }

    // SETTING PREFERENCES EQUAL YO NUMBER OF TOTAL VOTES
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (strcmp(namee[i][j], candidates[j].name) == 0)
            {
                preferences[i][j] = candidates[j].votes;
            }
        }
    }

    // Keep holding runoffs until winner exists
    bool won = print_winner();
    while (true)
    {
        // Calculate votes given remaining candidates
        for (int i = 0; i < 1; i++)
        {
            tabulate();
        }

        // Check if election has been won

        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
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

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}






// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    bool present_or_not;

    for(int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            //candidates[i].votes += 1;
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





// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            for (int k = 0; k < candidate_count; k++)
            {
                if (strcmp(namee[i][j], candidates[k].name) == 0)
                {
                    candidates[k].votes += candidate_count - j;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        printf("%s got %i votes.\n", candidates[i].name, candidates[i].votes);
    }


}





// Print the winner of the election, if there is one
bool print_winner(void)
{
    bool winner_present_or_not = false;

    int total_votes;
    int n = candidate_count;

    for(int i = 0; i < candidate_count; i++)
    {
        n = n * (i + 1);
    }

    total_votes = n * voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= total_votes / 2)
        {
            winner_present_or_not = true;
            break;
        }
        else if (i == candidate_count - 1 && candidates[i].votes >= total_votes / 2)
        {
            winner_present_or_not = true;
            break;
        }
    }

    return winner_present_or_not;
}





// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int n = candidate_count;
    int sorted[n];
    string names[n];
    int m = voter_count;

    // PREPARING TO SORT

    for (int i = 0; i < n; i++)
    {
        //candidates[i].votes = candidates[i].votes / n; // IDK THE OUTPUT WAS n TIMES THE ACTUAL VOTES
    }

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







// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    bool tie_or_not;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {

        }
        else if (i == candidate_count - 1 && candidates[candidate_count - 1].votes == min)
        {
            tie_or_not = true;
            break;
        }
        else
        {
            tie_or_not = false;
        }
    }

    return tie_or_not;
}






// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    string new_names[MAX_CANDIDATES];
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            for (int j = 0; j < i; j++)
            {
                candidates[j].name = candidates[j].name;
            }
            for (int k = i + 1; k < candidate_count; k++)
            {
                candidates[k].name = candidates[k].name;
            }
        }
    }
    return;
}