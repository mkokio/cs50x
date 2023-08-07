#include <stdio.h>
#include <cs50.h>

//how many years to have a population of n llamas
//every year n/3 are born
//every year n/4 pass away

int main(void)
{
    float c = get_float("How many llamas do you have? "); //current llamas
    float n = get_float("How many llamas do you need? "); //needed llamas
    int y;
    for (y = 0; c < n; y++)
    {
        c = c + (c * .3) - (c * .4);
        printf("Year %i: f% llamas.\n", y, c);
    }
    printf("After this many years: %i\n", y);
    printf("You now this may llamas: %f\n", c);
}