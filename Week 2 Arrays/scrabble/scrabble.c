#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int calc_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = calc_score(word1);
    int score2 = calc_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins with word%s\n", word1);
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins with word%s\n", word2);
    }
    else
    {
        printf("Tied with word %s\n", word1);
    }
}

int calc_score(string word)
{
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }
    return score;
}
