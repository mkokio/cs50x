#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    int n = 0;
    while (input[n] != '\0')
    {
        n++;
        int x = input[n];
        printf("DEC of the last digit is %i\n", x)
    }
    printf("Length of string: %i\n", n);
    //n is now the length of the string

    //Convert this char into its numeric value. Can you subtract some char to do this?
    int x = input[n];
    printf("DEC of the last digit is %i\n", x);

    //Remove the last char from the string by moving the null terminator one position to the left.

    //Return this value plus 10 times the integer value of the new shortened string.

    //Remember you need a base case when creating a recursive function.
}