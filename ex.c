#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <search.h>

typedef struct
{
    string name;
    int vote;
}
candidate;

int main(int argc, string argv[])
{
    // COMMAND LINE ARGUMNET

    if (argc > 9 || argc < 3)
    {
        printf("ERROR! Enter valid number of candidates!\n");
        return 1;
    }

    for (int i = 1 ; i < argc ; i++)
    {
        for (int j = 0 ; j < strlen(argv[i]) ; j++)
        {
            if (isalpha(argv[i][j]) == false)
            {
                printf("ERROR! Enter a valid candidate name!\n");
                return 1;
            }
        }
    }

    // NAME OF CANDIDATES

    candidate candidates[argc - 1];

    for (int i = 0 ; i < argc - 1 ; i++)
    {
        candidates[i].name = argv[i+1];
    }

    // NO. OF VOTERS

    int n = get_int("Number of voters: ");

    // NO. OF VOTES AND MAKING SURE IF ANY VOTES ARE INVALID

    for (int i = 0 ; i < argc - 1 ; i++)
    {
        candidates[i].vote = 0;
    }

    string votes[n];

    for (int i = 0 ; i < n ; i++)
    {
        votes[i] = get_string("Vote: ");

        for (int j = 0 ; j < argc - 1 ; j++)
        {
            if (strcmp(votes[i], candidates[j].name) == 0)
            {
                candidates[j].vote += 1;
                break;
            }
            else if (j == argc - 2 && strcmp(votes[i], candidates[j].name) != 0)
            {
                printf("Invalid vote.\n");
            }
        }
    }

    // DECIDING THE WINNER

    int sorted[argc - 1];

    for (int i = 0 ; i < argc - 2 ; i++)
    {
        for (int j = i + 1 ; j < argc - 1 ; j++)
        {
            if (candidates[i].vote > candidates[j].vote)
            {
                candidates[i].vote = candidates[j].vote;
                candidates[j].vote = candidates[i].vote;
                break;
            }
        }
    }

    printf("%s", candidates[argc - 1].name);
}

//printf("Invalid vote.\n");

