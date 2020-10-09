#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            average = round((image[i][k].rgbtBlue + image[i][k].rgbtGreen + image[i][k].rgbtRed) / 3.0);
            image[i][k].rgbtBlue = average;
            image[i][k].rgbtGreen = average;
            image[i][k].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue; //
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            sepiaRed = .393 * image[i][k].rgbtRed + .769 * image[i][k].rgbtGreen + .189 * image[i][k].rgbtBlue;
            sepiaGreen = .349 * image[i][k].rgbtRed  + .686 * image[i][k].rgbtGreen + .168 * image[i][k].rgbtBlue;
            sepiaBlue = .272 * image[i][k].rgbtRed + .534 * image[i][k].rgbtGreen + .131 * image[i][k].rgbtBlue;

            if (sepiaRed <= 255)
            {
                image[i][k].rgbtRed = round(sepiaRed);
            }
            else
            {
                image[i][k].rgbtRed = 255;
            }

            if (sepiaGreen <= 255)
            {
                image[i][k].rgbtGreen = round(sepiaGreen);
            }
            else
            {
                image[i][k].rgbtGreen = 255;
            }

            if (sepiaBlue <= 255)
            {
                image[i][k].rgbtBlue = round(sepiaBlue);
            }
            else
            {
                image[i][k].rgbtBlue = 255;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // int temp; // first variant
    RGBTRIPLE temp; // RGBTRIPLE is a custom structure type that contains the .rgbtBlue, .rgbtGreen and .rgbtRed
    // iterating vertical through the pixels vertical
    for (int i = 0; i < height; i++)
    {
        // iterating only on the first half width of the image and changing values between the first half and the second
        for (int k = 0; k < width / 2; k++) 
        {
            // new variant that doing the same, but at once for all three colors
            temp = image[i][k]; // temp stores the left pixel information
            image[i][k] = image[i][(width - 1) - k]; // left pixel = right pixel
            image[i][(width - 1) - k] = temp; // right pixel = temp (left pixel)
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float averageR, averageG, averageB; // average colors
    int count; // counter for the amount of pixels used to get the averages for each pixe
    float avR, avG, avB;
    RGBTRIPLE temp[height][width]; // an array for thhe image copy — need the temp array to get the average colors of the original pixels (not modified by the function)

    for (int i = 0; i < height; i++) // copy the image to temp array
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            avR = 0;
            avG = 0;
            avB = 0;
            count = 0;
            for (int i = - 1; i < 2; i++)
            {
                for (int k = - 1; k < 2; k++)
                {
                    if (w + k >= 0 && w + k <= width - 1 && h + i >= 0 && h + i <= height - 1)
                    {
                        avR += temp[h + i][w + k].rgbtRed;
                        avG += temp[h + i][w + k].rgbtGreen;
                        avB += temp[h + i][w + k].rgbtBlue;
                        count++;
                    }
                }
            }
            image[h][w].rgbtRed = round(avR / count);
            image[h][w].rgbtGreen = round(avG / count);
            image[h][w].rgbtBlue = round(avB / count);
        }
    }
    return;
}
