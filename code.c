#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    string names[] = {"Carter", "David"};
    long numbers[] = {1234567890, 7890654321};

    string name = get_string("Name: ");

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("%li", numbers[i]);
            return 0;
        }
    }

    printf("Not found");
    return 1;

}