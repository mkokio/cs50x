#include <stdio.h>
#include <cs50.h>

string prompt_name(void);
int prompt_age(void);
int prompt_phone_number(void);
void print_details(string n, int a, int p);

int main(void)
{
    string n = prompt_name();
    int a = prompt_age();
    int p =prompt_phone_number();
    print_details(n, a, p);
}

string prompt_name(void)
{
    string name = get_string("What's your name? ");
    return name;
}

int prompt_age(void)
{
    int age = get_int("How old are you? ");
    return age;
}

int prompt_phone_number(void)
{
    int phone_number = get_int("What's your phone number? ");
    return phone_number;
}

void print_details(char n, int a, int p)
{
    printf("Hello, %s.", n);
    printf("You are %i.", a);
    printf("Your phone number is %i.", p);
}