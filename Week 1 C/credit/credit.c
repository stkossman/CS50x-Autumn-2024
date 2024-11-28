#include <stdio.h>
#include <cs50.h>

int card_length(long number);
bool luhn_check(long number);

int main(void)
{
    long card = get_long("Number: ");
    if (luhn_check(card))
    {
        int length = card_length(card);
        long twodig = card;

        while (twodig >= 100)
        {
            twodig = twodig/10;
        }

        if (length == 15 && (twodig == 34 || twodig == 37))
        {
            printf("AMEX\n");
        }

        else if (length == 16 && (twodig >= 51 && twodig <= 55))
        {
            printf("MASTERCARD\n");
        }

        else if ((length == 13 || length == 16) && twodig / 10 == 4)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
        {
            printf("INVALID\n");
        }
}

int card_length(long number)
{
    int length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

bool luhn_check (long number)
{
    int sum = 0;
    bool alternate = false;

    int length = card_length(number);
    while (number > 0)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        number /= 10;
        alternate = !alternate;
    }
    return  (sum % 10 == 0);
}
