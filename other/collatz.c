#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int input = get_int("Type a whole number: ");
    int total_steps = collatz(input);
    printf("Steps to get to 1: %i/n", total_steps);
}

int collatz(int n)
{
    int steps = 0;
    if (n == 1)
    {
        return steps;
    }
    else if (n/2 == 0)
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