#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // printf("Score 1: %i\n", score1);
    // printf("Score 2: %i\n", score2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int points = 0;
    int n = 0;
    int score = 0;
    while (word[n] != '\0')
    {
        //convert uppercase to lowercase (add 32) and minus 97 to match real alphabet position
        if (word[n] >= 65 && word[n] <= 90)
        {
            word[n] += (32 - 97);
            // printf("%i letter is uppercase, ", n);
        }
        //use lowercase minus 97 to match real alphabet position
        else if (word[n] >= 97 && word[n] <= 122)
        {
            word[n] -= 97;
            // printf("%i letter is lowercase, ", n);
        }
        //ignore non letters
        else
        {
            word[n] = 26; //set score of that letter to position 26 which is worth zero
            // printf("%i letter is not a letter, ", n);
        }
        int position = word[n];
        points = POINTS[position];
        //printf("and it is in %i position, so worth this much: %i\n", position, points);
        n ++;
        score += points;
    }

    return score;
}
