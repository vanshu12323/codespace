#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   string s = get_string("Message: ");
   int ascii[strlen(s)];
   int remainder[];

   for (int i = 0 ; i < strlen(s) ; i++)
   {
      ascii[i] = s[i];

      for (int i = 0 ; i < strlen(s) ; i++)
      {
         remainder[i] = ascii[i] / 2
      }
   }



}