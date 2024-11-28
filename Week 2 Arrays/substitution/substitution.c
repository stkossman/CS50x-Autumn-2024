#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool valid(string str);

int main(int argc, char *argv[])
{
    if (argc != 2 || !valid(argv[1]))
    {
        printf("Usage: ./substitution (key)\n");
        return 1;
    }

    char input[500];
    printf("plaintext: ");
    fgets(input, sizeof(input), stdin);
    printf("\n");

    for (int i = 0; i < strlen(input); i++)
    {
        if (islower(input[i]))
        {
            input[i] = tolower(argv[1][input[i] - 97]);
        }
        else if (isupper(input[i]))
        {
            input[i] = toupper(argv[1][input[i] - 65]);
        }
    }

    printf("ciphertext: %s\n", input);
    return 0;
}

bool valid(string str)
{
    if (strlen(str) != 26)
    {
        printf("Key must contain 26 characters\n");
        return false;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(str[i]))
        {
            printf("Key must contain only alphabetic characters\n");
            return false;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(str[i]) == tolower(str[j]))
            {
                printf("Key must contain unique alphabetic characters\n");
                return false;
            }
        }
    }
    return true;
}
