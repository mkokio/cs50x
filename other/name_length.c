#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your first name? ");
    int n = 0;
    printf("These are the ascii (almost binary) codes to each letter of your name:\n");
    while (name[n] != '\0')
    {
        printf("%i ", name[n]);
        n++;
    }
    printf("\nYour name has this many letters! %i\n", n);
    printf("Last character ASCII code is %i\n", name[n-1]);
}
