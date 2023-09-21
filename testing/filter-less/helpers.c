#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //  Iterate through each pixel of the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0) //  Top Row
            {
                if (j == 0) //  First Pixel
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i][j + 1].rgbtBlue + tmp[i + 1][j].rgbtBlue + tmp[i + 1][j + 1].rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i][j + 1].rgbtGreen + tmp[i + 1][j].rgbtGreen + tmp[i + 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i][j + 1].rgbtRed + tmp[i + 1][j].rgbtRed + tmp[i + 1][j + 1].rgbtRed) / 4.0);
                }
                else if (j < width - 1) //  Middle but not last pixel
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i][j + 1].rgbtBlue + tmp[i + 1][j].rgbtBlue + tmp[i + 1][j + 1].rgbtBlue + tmp[i][j - 1].rgbtBlue + tmp[i + 1][j - 1].rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i][j + 1].rgbtGreen + tmp[i + 1][j].rgbtGreen + tmp[i + 1][j + 1].rgbtGreen + tmp[i][j - 1].rgbtGreen + tmp[i + 1][j - 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i][j + 1].rgbtRed + tmp[i + 1][j].rgbtRed + tmp[i + 1][j + 1].rgbtRed + tmp[i][j - 1].rgbtRed + tmp[i + 1][j - 1].rgbtRed) / 6.0);
                }
                else //  Last Pixel on top row
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i][j - 1].rgbtBlue + tmp[i + 1][j].rgbtBlue + tmp[i + 1][j - 1].rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i][j - 1].rgbtGreen + tmp[i + 1][j].rgbtGreen + tmp[i + 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i][j - 1].rgbtRed + tmp[i + 1][j].rgbtRed + tmp[i + 1][j - 1].rgbtRed) / 4.0);
                }
            }
            if (i > 0 && i < height - 1) //  Middle Rows
            {
                if (j == 0) //  First Column
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i][j + 1].rgbtBlue + tmp[i + 1][j].rgbtBlue + tmp[i + 1][j + 1].rgbtBlue + tmp[i - 1][j].rgbtBlue + tmp[i - 1][j + 1].rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i][j + 1].rgbtGreen + tmp[i + 1][j].rgbtGreen + tmp[i + 1][j + 1].rgbtGreen + tmp[i - 1][j].rgbtGreen + tmp[i - 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i][j + 1].rgbtRed + tmp[i + 1][j].rgbtRed + tmp[i + 1][j + 1].rgbtRed + tmp[i - 1][j].rgbtRed + tmp[i - 1][j + 1].rgbtRed) / 6.0);
                }
                else if (j < width - 1) //  Middle but not last pixel
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i][j + 1].rgbtBlue + tmp[i + 1][j].rgbtBlue + tmp[i + 1][j + 1].rgbtBlue + tmp[i - 1][j].rgbtBlue + tmp[i - 1][j + 1].rgbtBlue + tmp[i + 1][j - 1].rgbtBlue + tmp[i][j - 1].rgbtBlue + tmp[i - 1][j - 1].rgbtBlue) / 9.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i][j + 1].rgbtGreen + tmp[i + 1][j].rgbtGreen + tmp[i + 1][j + 1].rgbtGreen + tmp[i - 1][j].rgbtGreen + tmp[i - 1][j + 1].rgbtGreen + tmp[i + 1][j - 1].rgbtGreen + tmp[i][j - 1].rgbtGreen + tmp[i - 1][j - 1].rgbtGreen) / 9.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i][j + 1].rgbtRed + tmp[i + 1][j].rgbtRed + tmp[i + 1][j + 1].rgbtRed + tmp[i - 1][j].rgbtRed + tmp[i - 1][j + 1].rgbtRed + tmp[i + 1][j - 1].rgbtRed + tmp[i][j - 1].rgbtRed + tmp[i - 1][j - 1].rgbtRed) / 9.0);
                    }
                else // last pixel
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i + 1][j].rgbtBlue + tmp[i - 1][j].rgbtBlue + tmp[i - 1][j - 1].rgbtBlue + tmp[i + 1][j - 1].rgbtBlue + tmp[i][j - 1].rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i + 1][j].rgbtGreen + tmp[i - 1][j].rgbtGreen + tmp[i - 1][j - 1].rgbtGreen + tmp[i + 1][j - 1].rgbtGreen + tmp[i][j - 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i + 1][j].rgbtRed + tmp[i - 1][j].rgbtRed + tmp[i - 1][j - 1].rgbtRed + tmp[i + 1][j - 1].rgbtRed + tmp[i][j - 1].rgbtRed) / 6.0);
                }
            }
            if (i == height - 1) //  Last Row
            {
                if (j == 0) // First pixel
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i - 1][j].rgbtBlue + tmp[i - 1][j + 1].rgbtBlue + tmp[i][j + 1].rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i - 1][j].rgbtGreen + tmp[i - 1][j + 1].rgbtGreen + tmp[i][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i - 1][j].rgbtRed + tmp[i - 1][j + 1].rgbtRed + tmp[i][j + 1].rgbtRed) / 4.0);
                }
                else if (j < width - 1) // Middle Pixels
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i - 1][j].rgbtBlue + tmp[i - 1][j + 1].rgbtBlue + tmp[i][j + 1].rgbtBlue + tmp[i - 1][j].rgbtBlue + tmp[i - 1][j - 1].rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i - 1][j].rgbtGreen + tmp[i - 1][j + 1].rgbtGreen + tmp[i][j + 1].rgbtGreen + tmp[i - 1][j].rgbtGreen + tmp[i - 1][j - 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i - 1][j].rgbtRed + tmp[i - 1][j + 1].rgbtRed + tmp[i][j + 1].rgbtRed + tmp[i - 1][j].rgbtRed + tmp[i - 1][j - 1].rgbtRed) / 6.0);
                }
                else //  Last pixel
                {
                    image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue + tmp[i - 1][j].rgbtBlue + tmp[i][j - 1].rgbtBlue + tmp[i - 1][j - 1].rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen + tmp[i - 1][j].rgbtGreen + tmp[i][j - 1].rgbtGreen + tmp[i - 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((tmp[i][j].rgbtRed + tmp[i - 1][j].rgbtRed + tmp[i][j - 1].rgbtRed + tmp[i - 1][j - 1].rgbtRed) / 4.0);
                }
            }
        }
    }
}
