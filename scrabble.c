#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compute_score(string word);

int main(void)
{
    //TODO
    //INPUT OF A AND B
    //ASSIGN SCORE TO EACH ALPHABET
    // COMPUTE SCORE AND BASED ON IT PRINT WHETHER A OR B WINS OR IS IT A TIE

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    printf("%i and %i" , score1 , score2 );

}





int compute_score(string word)
{
    int points[] = {1 , 3 , 3 , 2 , 1 , 4 , 2 , 4 , 1 , 8 , 5 , 1 , 3 , 1 , 1 , 3 , 10 , 1 , 1 , 1 , 1 , 4 , 4 , 8 , 4 , 10};
    char alphabets[] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z'};

    int score = 0;

    for (int i = 0 ; i < strlen(word) ; i++)
    {
        char character = tolower(word[i]);
         int m = 0;

        for (m = 0 ; character != alphabets[m] ; m++)
        {
            /*if (character >= alphabets[0] || character <= alphabets[25])
            {
                m+=0;
            }*/
        }

        /*do
        {
            m++;
        }
        while(character != alphabets[m] || character >= alphabets[0] || character <= alphabets[25]); */

        score += points[m];
    }
    return score;
}
