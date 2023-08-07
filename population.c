#include <stdio.h>
#include <cs50.h>

//how many years to have a population of n llamas
//every year n/3 are born
//every year n/4 pass away

int main(void)
{
    //current llamas
    int c = get_int("How many llamas do you have? ");

    //needed llamas
    int n;
    do
    {
        get_int("How many llamas do you need? ");
    }
    while (n < c);

    //do the math
    int y;
    for (y = 0; c < n; y++)
    {
        printf("Year %i: %i llamas.\n", y, c);
        c = c + (c/3) - (c/4);
    }

    //print result
    printf("After this many years: %i\n", y);
    printf("You now this may llamas: %i\n", c);
}