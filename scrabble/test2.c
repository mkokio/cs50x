#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char ALPHABET[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(string word);

int main(void)
{
    string word = "banana";

    //convert fully to lowercase
    if (word[0] >= 60 && word[0] <= 90)
    {
        word[0] += 32 - 97;
    }
    //ignore non letters
    else if (word[0] >= 0 && word[0] <= 64)
    {
        word[0] = 0;
    }
    //ignore non letters
    else if (word[0] >= 91 && word[0] <= 96)
    {
        word[0] = 0;
    }
    //ignore non letters
    else if (word[0] >= 123)
    {
        word[0] = 0;
    }
    else
    {
        word[0] -= 97;
    }
    printf("%i\n", word[0]);
}
