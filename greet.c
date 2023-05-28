#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("Hello , %s" , name);
}