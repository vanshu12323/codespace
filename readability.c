#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");

    int l = count_letters(text);
    //int w = count_words(text);
    //int s = count_sentences(text);
    printf("%i", l);


}






int count_letters(string text)
{
    int l = 0;

    for(int i = 0 ; i < strlen(text) ; i++)
    {
        if (isupper(text[i]))
        {
            l++;
        }
        else if (islower(text[i]))
        {
            l++;
        }
        else
        {
            l += 0;
        }
    }
    return l;
}





int count_words(string text)
{
    
}

