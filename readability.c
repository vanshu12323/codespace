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

    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);

    printf("%i letters\n", l);
    printf("%i words\n", w);
    printf("%i sentences\n", s);

    float m = (l / w)*100;
    float n = (s / w)*100;

    printf("%f and %f", m, n);

    float index = (0.0588 * m) - (0.296 * n) - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+");
    }
    else if (index < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %f", index);
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

