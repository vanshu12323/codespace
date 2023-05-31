#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string key);

int main(int argc , string argv[])
{
    /*do
    {
        key = get_int("");
    }
    while (key < 0);*/

    if (argc != 2)
    {
        printf("ERROR : Enter a valid key!");
        return 1;
    }
    else if (argv[1] < 0)
    {
        printf("ERROR : Enter a valid key!");
        return 1;
    }
    else
    {
        string text = get_string("plaintext: ");
    }
}

bool only_digits(string key)
{
    return 0;
}