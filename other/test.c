#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    int n = 0;
    while (input[n] != '\0')
    {
        n++;
    }
    printf("Length of string: %i\n", n);
    //n is now the length of the string

    //Convert this char into its numeric value. Can you subtract some char to do this?
    int x = input[n];
    printf("Last character is %c\n", x);

    //Remove the last char from the string by moving the null terminator one position to the left.

    //Return this value plus 10 times the integer value of the new shortened string.

    //Remember you need a base case when creating a recursive function.
}