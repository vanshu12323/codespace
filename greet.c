#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(int argc , string argv[])
{
   if (argc != 2)
   {
    printf("Missing command-line Argument");
    return 1;
   }
   else
   {
    printf("Hello , %s" , argv[1]);
   }
}