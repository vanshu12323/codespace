#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int print_bulb(string message);

int main(void)
{
    string on ="🟡";
    string off = "⚫";
    string message = get_string("Message: ");

    int m = print_bulb(message);

    printf("%i" , m);

    //printf("%i", print_bulb(message));

}



int print_bulb(string message)
{
    int ascii;
    int remainder[8 * strlen(message)];
    for (int i = 0 ; i < strlen(message) ; i++ , ascii = (int)ascii / (int)2)
    {
        ascii = message[i];

        for (int j = 0 ; j < 9 ; j++)
        {
            remainder[j] = ascii % 2;
        }
    }

    int remainder = 0;
    while (n != 0)
    {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
    }

}