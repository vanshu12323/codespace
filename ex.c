#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = "dog'';;";
   // char dd[] = {'d' , 'g' , 'o'};
   // char qq = s[2];
    //printf("%c" , qq);
    //printf("%i" , dd[2]);
    for (int i = 0 ; i < strlen(s) ; i++)
    {
            printf("%c" , toupper(s[i]) );
    }

}