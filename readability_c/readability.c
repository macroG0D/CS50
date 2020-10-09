#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Enter the text: ");
    int letters = 0;
    int sentences = 0;
    int words = 1;
  
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
        else if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
    }
  
    float W = 100.0 / words;
    float L = letters * W;
    float S = sentences * W;
  
    // Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    float index = ((0.0588 * L) - (0.296 * S)) - 15.8;
  
    if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }

}