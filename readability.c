#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");

    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);


}