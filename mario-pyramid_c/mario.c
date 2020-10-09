#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input = 0;
    do
    {
        input = get_int("Input a number between 1 to 8, inclusive: ");
    }
    while (input < 1 || input > 8);
    
    
    for (int i = 1; i <= input; i++)
    {
        for (int j = 1; j <= input - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        
        for (int m = 1; m <= i; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}