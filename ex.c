#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   string s = get_string("Message: ");
   int ascii[strlen(s)];
   int remainder[8 * strlen(s)];

   for (int i = 0 ; i < strlen(s) ; i++)
   {
      ascii[i] = s[i];

      for (int j = 0 ; j < 8 ; j++ , ascii[i] /= 2)
      {
         remainder[j] = ascii[i] % 2;
        // ascii /= 2;
         printf("%i", remainder[j]);
      }
      printf("\n");
   }

   for (int i = 0 ; i < strlen(s) ; i++)
   {
      for (int j = 7 ; j >= 0 ; j--)
      {
         printf("%i" , remainder[i][j]);
      }
   }

   string name = "SHREYA";
   for(int i = strlen(name) ; i >= 0 ; i--)
   {
      printf("%c" , name[i]);
   }


}