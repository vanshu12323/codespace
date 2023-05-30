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
    printf("%i %i", print_bulb(message) , print_bulb(message));

}



int print_bulb(string message)
{
    for (int i = 0 ; i < strlen(message) ; i++)
    {
        int ascii = message[i];

        for ()
        {
            
        }
    }

}