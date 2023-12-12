#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int pyramidHeight;
    int spaces;
    int j;
    int i;

    do
    {
        pyramidHeight = get_int("Height: ");
    }
    while (pyramidHeight < 1 || pyramidHeight > 8);

    for (i = 1; i < pyramidHeight + 1; i++)
    {
        spaces = pyramidHeight - i;
        for (j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
