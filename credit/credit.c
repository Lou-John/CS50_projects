#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number_size;
    int luhn_number = 0;
    int temp;
    int other_numbers = 0;
    long number;
    long first;
    long second = -1;
    string card_type = "INVALID";
    bool other = true;

    // Prompt the user for card numbers
    number = get_long("Number: ");
    number_size = floor(log10(number)) + 1;

    // Check if number is of valid lenghts
    if (number_size != 13 && number_size != 15 && number_size != 16)
    {
        printf("%s\n", card_type);
        exit(0);
    }

    // Recuperating first and second digits from long
    first = number;
    do
    {
        if (first < 1000 && second == -1)
        {
            second = (first / 10) % 10;
        }
        first = first / 10;
    }
    while (first >= 10);

    // Checking card type
    if (first == 4)
    {
        if (number_size == 13 || number_size == 16)
        {
            card_type = "VISA";
        }
    }
    else if (first == 3 && number_size == 15)
    {
        if (second == 4 || second == 7)
        {
            card_type = "AMEX";
        }
    }
    else if (first == 5 && number_size == 16)
    {
        if (second == 1 || second == 2 || second == 3 || second == 4 || second == 5)
        {
            card_type = "MASTERCARD";
        }
    }

    // Checking Luhn's Algorithm
    temp = number;
    for (int i = number_size; i > 0; i--)
    {
        if (other == true)
        {
            // printf("Others: %lu\n", (number  % 10));
            other_numbers += (number % 10);
            number /= 10;
            other = false;
        }
        else
        {
            temp = number % 10;
            number /= 10;
            // printf("Luhn: %d\n", (temp  % 10));
            temp *= 2;

            if (temp >= 10)
            {
                luhn_number += ((temp / 10) % 10) + (temp % 10);
            }
            else
            {
                luhn_number += temp;
            }
            other = true;
        }
    }
    // printf("Luhn: %d Other: %d", luhn_number, other_numbers);
    if ((luhn_number + other_numbers) % 10 != 0)
    {
        card_type = "INVALID";
    }

    printf("%s\n", card_type);
}
