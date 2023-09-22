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
            int totalR = 0;
            int totalG = 0;
            int totalB = 0;
            float count = 0.0;

            // loop through all surrounding pixels
            for (int a = i - 1; a < i + 2; a++)
            {
                for (int b = j - 1; b < j + 2; b++)
                {
                    if (a >= 0 && a < height && b >= 0 && b < width)
                    {
                        totalR += tmp[a][b].rgbtRed;
                        totalG += tmp[a][b].rgbtGreen;
                        totalB += tmp[a][b].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(totalR / count);
            image[i][j].rgbtGreen = round(totalG / count);
            image[i][j].rgbtBlue = round(totalB / count);
        }
    }
}