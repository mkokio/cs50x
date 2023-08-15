#include <cs50.h>
#include <stdio.h>
#include <ctype.h>


// index = 0.0588 * L - 0.296 * S - 15.8
// L is average number of letters per 100 words
// S is average number of sentences per 100 words in the text

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //prompt user for input
    string text = get_string("Text: ");

    //count number of letters (a-z & A-Z)
    int character_count = count_letters(text);

    //count number of words (separated by a space)
    int word_count = count_words(text);

    //count number of sentences (period, exclamation or question mark)
    int sentence_count = count_sentences(text);

    //print result "Grade X" rounded to nearest integer.
    // X can be "Before Grade 1", 1 to 16, or "16+"


    //delete before submit
    printf("Characters: %i\n", character_count);
    printf("Words: %i\n", word_count);
    printf("Sentences: %i\n", sentence_count);
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