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


}

int count_letters(string text)
{
    return strlen(text);
}