#include "helpers.h"
#include <math.h>
#include <stdio.h>

//  Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int grey = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtRed = grey;
        }
    }
}

//  Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            int sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            int sepiaRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
}

//  Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //  pixel at image[i][0] need to be swapped with pixel at image[i][width]
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

//  Blur image
// Sure, after copying the image, you can start by creating
// two nested loops to iterate over each pixel in the image.
// For each pixel, you'll need to create another set of nested loops
// to iterate over the pixel's neighbors. Remember to check if each neighbor
// is valid before including it in your calculations.
// Calculate the sum of the RGB values of the valid neighbors,
// count the number of valid neighbors, and then calculate the average.
// Assign these averages to the corresponding pixel in the original image.
// You can simply declare an integer variable and increment it each time you
// find a valid neighbor. For example, you might start with
// int valid_neighbors = 0; and then add 1 to valid_neighbors each time you find a valid neighbor pixel.
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //  Make a copy of the image
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }
    // iterate over image's pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // iterate over the pixel's neighbors and check if valid
            tmp[i-1][j-1]
            tmp[i-1][j]
            tmp[i-1][j+1]
            tmp[i][j-1]
            tmp[i][j]
            tmp[i][j+1]
            tmp[i+1][j-1]
            tmp[i+1][j]
            tmp[i+1][j+1]
        }
    }
}