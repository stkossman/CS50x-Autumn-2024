#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dime(int cents);
int calculate_nickel(int cents);
int calculate_penny(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    int dime = calculate_dime(cents);
    cents = cents - (dime * 10);

    int nickels = calculate_nickel(cents);
    cents = cents - (nickels * 5);

    int pennies = calculate_penny(cents);
    cents = cents - (pennies * 1);

    printf("Quarters:%i\n", quarters);
    printf("Dimes:%i\n", dime);
    printf("Nickels:%i\n", nickels);
    printf("Pennies:%i\n", pennies);
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dime(int cents)
{
    int dime = 0;
    while (cents >= 10)
    {
        dime++;
        cents = cents - 10;
    }
    return dime;
}

int calculate_nickel(int cents)
{
    int nickel = 0;
    while (cents >= 5)
    {
        nickel ++;
        cents = cents - 5;
    }
    return nickel;
}

int calculate_penny(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies ++;
        cents = cents - 1;
    }
    return pennies;
}
