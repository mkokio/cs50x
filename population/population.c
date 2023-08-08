#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int c;
    do
    {
        c = get_int("How many llamas do you have? ");
        if (c < 9)
        {
            printf("Protip, you need more than eight.\n");
        }
    }
    while (c < 9);

    // TODO: Prompt for end size
    int n;
    do
    {
        n = get_int("How many llamas do you need? ");
    }
    while (n < c);

    // TODO: Calculate number of years until we reach threshold
    int y;
    for (y = 0; c < n; y++)
    {
        // printf("Year %i: %i llamas.\n", y, c);
        c = c + (c / 3) - (c / 4); //+= c/12;
    }

    // TODO: Print number of years
    printf("Years: %i\n", y);
    // printf("You now this may llamas: %i\n", c);
}
