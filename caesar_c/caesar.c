#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int k; // the key variable
    if (argc == 2) // cheking if got one argument from user
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) // itterating through the user's argument characters
        {
            if (argv[1][i] < 48 || argv[1][i] > 57) // if input is not a number — return error
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        k = atoi(argv[1]); // we checked that the input is a number so converting it to integer and assign it to k
        if (k <= 0) // if the number is to big for integer (-1) or it just a 0 — return error
        {
            printf("Invalid input\n");
            return 1;
        }
    }
    else // if no argument or more then one argument — return error
    {
        printf("Invalid input\n");
        return 1;
    }

    // printf("The key is: %i\n", k); // printing the key
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++) // iteration through the plaintext characters
    {
        if (isupper(plaintext[i])) //  if char is uppercase letter
        {
            if (plaintext[i] + k > 89) //if rotation is bigger than uppercase aplphabet last character, than start rotation from A
            {
                int x = plaintext[i] - 65;
                x = (x + k) % 26 + 65;
                printf("%c", x);
            }
            else
            {
                printf("%c", plaintext[i] + k);
            }
        }
        else if (islower(plaintext[i])) //if char is lowercase letter
        {
            if (plaintext[i] + k > 122) //if rotation is bigger than lowarcase aplphabet last character, than start rotation from a
            {
                int x = plaintext[i] - 97;
                x = (x + k) % 26 + 97;
                printf("%c", x);
            }
            else
            {
                printf("%c", plaintext[i] + k);
            }
        }
        else // if char is not an alphabetical letter, then just printing it
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;

}

