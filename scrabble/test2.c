#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    char word[] = "b";

    //convert uppercase to lowercase (add 32) and minus 97 to match real alphabet position
    if (word[0] >= 65 && word[0] <= 90)
    {
        word[0] += (32 - 97);
    }
    //use lowercase minus 97 to match real alphabet position
    else if (word[0] >= 97 && word[0] <= 122)
    {
        word[0] -= 97;
    }
    //ignore non letters
    else
    {
        word[0] = 0; //set score of that letter to zero
    }
    int position = word[0];
    printf("%i\n", POINTS[position]);
}
