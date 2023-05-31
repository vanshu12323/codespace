#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    do
    {
        int key = get_int("");
    }
    while (key < 0);
    string text = get_string("plaintext: ");
}