#include <cs50.h>
#include <stdio.h>

// index = 0.0588 * L - 0.296 * S - 15.8
// L is average number of letters per 100 words
// S is average number of sentences per 100 words in the text

int count_letters(string text);

int main(void)
{
    //prompt user for input
    string text = get_string("Text: ");

    //count number of letters (a-z & A-Z)
    count_letters(text);

    //count number of words (separated by a space)

    //count number of sentences (period, exclamation or question mark)

    //print result "Grade X" rounded to nearest integer.
    // X can be "Before Grade 1", 1 to 16, or "16+"

}

int count_letters(string text)
{
    int n = 0;

    while (text[n] != "." || text[n] != "!" || text[n] != "?")
    {
        n++;
    }
    printf("This many characters before the end: %i\n", n);
}