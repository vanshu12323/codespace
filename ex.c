#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   string s = get_string("Message: ");
   int ascii[strlen(s)];

   for (int i = 0 ; i < strlen(s) ; i++)
   {
      ascii[i] = s[i];
   }

   

}