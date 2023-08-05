#include <stdio.h>
#include <cs50.h>

int get_size(void); //basically initializing or importing these functions,
void print_square(int size); //as "main" is usually at the top

int main(void)
{
    int n = get_size();
    print_square(n);
}

int get_size(void) //output return is integer, name is "get_size", no argument or parameter
{
    int n;
        do
        {
            n = get_int("Size of each square's side? ");
        }
        while (n < 1); //if the user enters a value less than 1, the while loop will execute again
        return n;
}

void print_square(int size) //no output type, name is "print_square", parameter is the size of desired square
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("X");
        }
        printf("\n");
    }
}