#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   int i[] = {1,2,3,4,5,6,7};
   int j = 0;

   do
   {
    j++;
   }
   while (j <= i[6]);

   printf("%i" , j);
}