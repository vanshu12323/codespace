#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string s = get_string("Name? ");

    for (int i = 0 ; i < strlen(s) ; i++)
    {
            printf("%c" , toupper(s[i]) );
    }
}