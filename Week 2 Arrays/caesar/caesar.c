#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool numeric(string str);

int main(int argc, char *argv[])
{
    if (argc != 2 || !numeric(argv[1]))
    {
        printf("Usage: ./caeser (key)\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", ((text[i] - 'A' + key) % 26) + 'A');
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%c", ((text[i] - 'a' + key) % 26) + 'a');
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}

bool numeric(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
