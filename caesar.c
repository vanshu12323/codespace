#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc , int argv[])
{
    /*int key;
    do
    {
        key = get_int("");
    }
    while (key < 0);*/

    if (argc != 2 && argv[1] < 0)
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