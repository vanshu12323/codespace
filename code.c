#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void draw(int n);

int main(void)
{
    //int height = get_int("Height: ");

    draw(1);
}





void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }

    printf("\n");

    draw(n + 1);
}