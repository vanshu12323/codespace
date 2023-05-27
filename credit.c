#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool check(long long credit);
int find_length(long long credit);

int main(void)
{

    long long credit = get_long_long("Number: ");

    if (check(credit))
    {
        printf("%lli" , credit);
    }
    else
    {
        printf("INVALID\n");
    }
    printf("%lli", find_length);

}

bool check(long long credit)
{
    int len = find_length(credit);
    return (len == 13 || len == 15 || len == 16);
    // ^ short way of saying if (soemthing something) -> is true return true else return false
}

int find_length(long long credit)
{
    int len = 0;

    for (len = 0 ; len % 10 >= 0 ; len++)
    {
        len = credit / 10;
    }
    return (len);
}

