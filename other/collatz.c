#include <cs50.h>
#include <stdio.h>

void collatz(int n);

int main(void)
{
    int input = get_int("Type a whole number: ");
    collatz(input);
    //printf("Steps to get to 1: %i/n", total_steps);
}

void collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if ((n%2) == 0)
    {
        n = n/2;
        steps++;
    }
    else
    {
        n = 3 * n + 1;
        steps++;
    }
    collatz(n);

}