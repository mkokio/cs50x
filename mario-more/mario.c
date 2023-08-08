#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for height
    int h = get_int("Height: ");
    //make a condition wherein only 1 to 8 inclusive are accepted

    //print (h-1) spaces, decreasing until zero
    int s;
    for (s = h-1; s > 0; s--)
    {
        printf(".");
    }
    //print 1 block, increasing on each row
    printf("#");
    
    printf("-middlespace-");


    printf("\nDONE\n");
}