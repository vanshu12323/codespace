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

    for (int i = 1 ; i < length ; i++)
    {
            if ((int)text[i] < (int)text[i - 1])
            {
                printf("No");
                return 0;
            }
            else
            {
                printf("Yes");
                return 0;
            }
    }
}