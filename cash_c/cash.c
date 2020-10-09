#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float input = 0;
    int coins = 0;

    do
    {
        input = get_float("Input your change owed: ");
    }
    while (input <= 0);

    int cents = round(input * 100);

    for (int i = cents; i >= 0; i--)
    {
        if (cents >= 25)
        {
            cents -= 25;
            coins += 1;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            coins += 1;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            coins += 1;
        }
        else if (cents >= 1)
        {
            cents -= 1;
            coins += 1;
        }
    }

    printf("coins: %i\n", coins);

}