#include <cs50.h>
#include <stdio.h>

const N = 3; //the length of your array; how many numbers do you want the average of?

int get_average(int length, int array[]);

int main (void)
{
    int numbers[N];
    printf("Let's get the average of %i numbers.\n", N)
    for(int i; i < N; i++)
    {
        numbers[i] = get_int("Write a number: ")
    }
    printf("The average of the %i numbers is: %f\n", N, get_average(N, numbers))
}

int get_average(int length, int array[]);
{
    int sum = 0;
    for (int i = 0, )
}