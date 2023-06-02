#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}



void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

    if (n <= 0)
    {
        return;
    }
    draw(n - 1);
}