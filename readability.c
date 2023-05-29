#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    //Count number of letters, words, sentences

    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);

    double m = ((float)l / w) * 100.0;
    double n = ((float)s / w) * 100.0;

    //Calculate index

    float index = (0.0588 * m) - (0.296 * n) - 15.8;
    int k = round(index);

    //Print result

    if (k >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (k < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", k);
    }
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
    int w = 1;

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == ' ')
        {
            w++;
        }
    }
    return w;
}











int count_sentences(string text)
{
    int s = 0;

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == '.')
        {
            s++;
        }
        else if (text[i] == '?')
        {
            s++;
        }
        else if (text[i] == '!')
        {
            s++;
        }
    }
    return s;
}

