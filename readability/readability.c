#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void Coleman_Liau(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    // Count the letters, words and sentences in the text.
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the grade value according to the Coleman-Liau index
    Coleman_Liau(letters, words, sentences);
}

int count_letters(string text)
{
    int temp = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            temp += 1;
        }
    }
    return (temp);
}

int count_words(string text)
{
    int temp = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            temp += 1;
        }
    }
    return (temp + 1);
}

int count_sentences(string text)
{
    int temp = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            temp += 1;
        }
    }
    return (temp);
}

void Coleman_Liau(int letters, int words, int sentences)
{
    // printf("Letters: %i\nWords: %i\nSentences: %i\n", letters, words, sentences);
    // printf("Grade: %lf\n", 0.0588 * ((float)letters/words * 100) - 0.296 * ((float)sentences/words * 100) - 15.8);
    int grade = round(0.0588 * ((float) letters / words * 100) - 0.296 * ((float) sentences / words * 100) - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
