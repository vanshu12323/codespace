#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int m[4] = {3,1,2,0};
    int s[4] = {3,1,2,0};

    for (int i = 0; i < 4; i++)
    {
        for (int  j= 0; j < 4; j++)
        {
            if (m[i] > m[j])
            {
                s[i] = m[j];
                s[j] = m[i];
                m[i] = s[i];
                m[j] = s[j];
            }
        }
    }
    for (int i = 3; i >= 0; i--)
    {
        printf("%i ", s[i]);
    }
}