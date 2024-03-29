#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void reading_level(int c, int w, int s);

int main(void)
{
    // prompt user for input
    string text = get_string("Text: ");

    // count number of letters (a-z & A-Z)
    int character_count = count_letters(text);

    // count number of words (separated by a space)
    int word_count = count_words(text);

    // count number of sentences (period, exclamation or question mark)
    int sentence_count = count_sentences(text);

    // calculate reading level
    reading_level(character_count, word_count, sentence_count);
}

int count_letters(string text)
{
    int n = 0;
    int char_count = 0;
    while (text[n] != '\0')
    {
        if (isalpha(text[n]))
        {
            char_count++;
        }
        n++;
    }
    return char_count;
}

int count_words(string text)
{
    int n = 0;
    int word_count = 1;
    while (text[n] != '\0')
    {
        if (text[n] == ' ')
        {
            word_count++;
        }
        n++;
    }
    return word_count;
}

int count_sentences(string text)
{
    int n = 0;
    int sent_count = 0;
    while (text[n] != '\0')
    {
        if (text[n] == '.' || text[n] == '!' || text[n] == '?')
        {
            sent_count++;
        }
        n++;
    }
    return sent_count;
}

void reading_level(int c, int w, int s)
{
    double L = c / (float) w * 100;
    double S = s / (float) w * 100;
    double index = (0.0588 * L - 0.296 * S - 15.8);

    if (index < 2)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 2 && index < 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}