#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get the size
    int n = get_size()

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("O");
        }
        printf("\n");
    }
}

int get_size(void) //output return is integer, name is "get_size", no argument or parameter
{
    int n;
        do
        {
            n = get_int("Size of each square's side? ");
        }
        while (n < 1);
}