#include <stdio.h>
#include <cs50.h>

char prompt_style();
int get_size(void); //basically initializing or importing these functions,
void print_square(int size, char style); //as "main" is usually at the top

int main(void)
{
    char style = prompt_style();
    int n = get_size();
    print_square(n, style);
}

char prompt_style(void)
{
    char style;
    do
    {
        style = get_char("What kind of square? Select [p][s][b] ");
    }
    while (style != 'p' && style != 's' && style != 'b');
    return style;
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

void print_square(int size, char style) //no output type, name is "print_square", parameter is the size of desired square
{
    char output[5]; // Sufficient space to store any Unicode character
    if (style == 'p')
    {
        output[0] = 0xF0;
        output[1] = 0x9F;
        output[2] = 0x92;
        output[3] = 0xA9;
        output[4] = '\0'; // Null-terminate the string
    }
    else if (style == 's')
    {
        output[0] = 0xE2;
        output[1] = 0x98;
        output[2] = 0x86;
        output[3] = '\0'; // Null-terminate the string
    }
    else
    {
        output[0] = 0xF0;
        output[1] = 0x9F;
        output[2] = 0x8D;
        output[3] = 0x8C;
        output[4] = '\0'; // Null-terminate the string
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%s", output);
        }
        printf("\n");
    }
    printf("Cool square!\n");
    printf("You used %i\u00B2 of %s.\n",size, output);
}

// \u2606 star
// \U0001F4A9 poop
// \u1F34C banana