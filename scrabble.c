#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //TODO
    //INPUT OF A AND B
    //ASSIGN SCORE TO EACH ALPHABET
    // COMPUTE SCORE AND BASED ON IT PRINT WHETHER A OR B WINS OR IS IT A TIE

    string aa = get_string("Player 1: ");
    string bb = get_string("Player 2: ");

    int points[] = {1 == 'a' , 3 , 3, 2 , 1 , 4 , 2 , 4 , 1 , 8 , 5 , 1 , 3 , 1 , 1 , 3 , 10 , 1 , 1 , 1 , 1 , 4 , 4 , 8 , 4 , 10};

    for (int i = 0 , n = strlen(aa) ; i < n ; i++)
    {
        if ((aa[i] >= 'a' && aa[i] <= 'z') || (aa[i] >= 'A' && aa[i] <= 'Z'))
        {
            printf("%i " , aa[i]);
        }
    }
}
