#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt for 1 to 8
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);


    for (int r = 0; r < h; r++)
    {
        //do this each row
        for (int s = h - r - 1; s > 0; s--)
        {
            printf(".");
        }
        for (int b = r; b < h; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}