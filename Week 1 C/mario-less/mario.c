#include <stdio.h>
#include <cs50.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int n;

    do
    {
        n = get_int("height: ");
    }
    while (n < 1);

    for(int i = 0; i < n; i++)
    {
        print_row(n - i - 1, i + 1);

    }
}

void print_row(int spaces, int bricks)
{
     for (int i = 0; i < spaces; i++)
     {
        printf(" ");
     }

     for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
