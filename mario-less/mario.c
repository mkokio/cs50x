#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for 1 to 8
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // Do this each row
    for (int r = 0; r < h; r++)
    {

        // Print (height - row number) spaces
        for (int s = h - r - 1; s > 0; s--)
        {
            printf(" ");
        }

        // Print (row number) of blocks
        for (int b = 0; b < r + 1; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}