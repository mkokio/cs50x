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

get_size(void)
{
    int n;
        do
        {
            n = get_int("Size of each square's side? ");
        }
        while (n < 1);
}