#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   string i = "123456";

   for(int j = strlen(i) ; j >= 0 ; j--)
   {
      printf("%c" , i[j]);
   }
}