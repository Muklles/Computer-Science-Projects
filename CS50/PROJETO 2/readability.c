#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string text);
int words(string text);
int sentences(string text);

int main(void)
{
    string text = get_string("Text: \n");

    int letter = letters(text);
    int word = words(text);
    int sentence = sentences(text);

    float L = (float) letter / word * 100.0;
    float S = (float) sentence / word * 100.0;
    float grade = 0.0588 * L - 0.296 * S - 15.8;

    // function to round the grade to the nearest int
    int rounded_grade = round(grade);
    if (rounded_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded_grade);
    }
}

// function to check how many letters
int letters(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// function to check how many words
int words(string text)
{
    int count = 0;
    bool in_word = false;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isspace(text[i]))
        {
            if (!in_word)
            {
                count++;
                in_word = true;
            }
        }
        else
        {
            in_word = false;
        }
    }
    return count;
}

// function to check how many sentences
int sentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
