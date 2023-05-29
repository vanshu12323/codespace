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

    for (int i = 0 ; i < strlen(message) ; i++)
    {
        ascii = message[i];
    }
    return ascii;
}