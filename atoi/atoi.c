#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO

    //Start by getting the index of the last char in the string (the char before the \0).
    int n = 0;
    while (input[n] != '\0')
    {
        n++;
    }
    printf("Length of string: %i\n", n);
    //n is now the length of the string

    //Convert this char into its numeric value. Can you subtract some char to do this?
    //Last character ASCII code is (int) input[n-1]
    int real_integer = input[n-1] - 48;
    printf("Real integer: %i\n", real_integer);

    //Remove the last char from the string by moving the null terminator one position to the left.
    input

    //Return this value plus 10 times the integer value of the new shortened string.

    //Remember you need a base case when creating a recursive function.
}