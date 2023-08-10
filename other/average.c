#include <cs50.h>
#include <stdio.h>

const int N = 3; // the length of your array; how many numbers do you want the average of?

float get_average(int length, int array[]);

int main(void)
{
    int numbers[N];
    printf("Let's get the average of %i numbers.\n", N);
    for (int i = 0; i < N; i++)
    {
        numbers[i] = get_int("Write a number: ");
    }
    printf("The average of the %i numbers is: %f\n", N, get_average(N, numbers));
}

float get_average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}