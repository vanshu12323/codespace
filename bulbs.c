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
    printf("%i", print_bulb(message));

}



int print_bulb(string message)
{
   int ascii;
   int remainder[8];
    for (int i = 0 ; i < strlen(message) ; i++)
    {
        ascii = message[i];

        for (int j = 0 ; j < 9 ; j++)
        {
            remainder[j] = ascii % 2;
            ascii = ascii / 2;
        }
    }

    
}