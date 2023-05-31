#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc , string argv[])
{
    /*int key;
    do
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
    //string text = get_string("plaintext: ");
}