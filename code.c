#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);

    for (int i = 0 ; i < length ; i++)
    {
        if (islower(text[i]))
        {
            if ((int)text[i] < (int)text[i + 1])
            {
                printf("Yes");
            }
            else
            {
                printf("No");
            }
        }
    }
}