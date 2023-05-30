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

        for (int j = 8 * i  ; j <= 8 * i + 7 ; j++, ascii[i] /= 2)
        {
            remainder[j] = ascii[i] % 2;
        }
    }


    for (int i = 0 ; i < strlen(s) ; i++)
    {
         for (int j = 8 * i + 7; j >= 8 * i ; j--)
         {
         }
    }


    for (int i = 0 ; i < strlen(s) ; i++)
    {
         for (int j = 8 * i + 7 ; j >= 8 * i ; j--)
         {
            if (remainder[j] == 1)
            {
                printf("🟡");
            }
            else if (remainder[j] == 0)
            {
                printf("⚫");
            }
         }
         printf("\n");
   }



   /*string name = "SHREYA";
   for(int i = strlen(name) ; i >= 0 ; i--)
   {
      printf("%c" , name[i]);
   }*/
   //printf("%i" , remainder[15]);
  // printf("%lu" , strlen(s));

}