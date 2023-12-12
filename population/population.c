#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;
    int yearsTaken;

    // TODO: Prompt for start size
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    yearsTaken = 0;
    do
    {
        if (endSize == startSize)
        {
            break;
        }
        startSize += (startSize / 3) - (startSize / 4);
        yearsTaken += 1;
    }
    while (endSize > startSize);

    // TODO: Print number of years
    printf("Years: %i\n", yearsTaken);
}
