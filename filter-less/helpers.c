#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            int grey = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);
            image[i][j].rgbtBlue = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtRed = grey;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width/2; j++)
        {
            // pixel at image[i][0] need to be swapped with pixel at image[i][width]
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make a copy of the image
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i ++)
        {
            for (int j = 0; j < width; j++)
            {
                tmp[i][j] = image[i][j];

            }
        }
    // Iterate through each pixel of the original image
    for (int i = 0; i < height; i ++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0) // Top Row
                    {
                        if (j == 0) // First Pixel
                        {
                            image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue+tmp[i][j+1].rgbtBlue+tmp[i+1][j].rgbtBlue+tmp[i+1][j+1].rgbtBlue)/4);
                            image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen+tmp[i][j+1].rgbtGreen+tmp[i+1][j].rgbtGreen+tmp[i+1][j+1].rgbtGreen)/4);
                            image[i][j].rgbtRed = round((tmp[i][j].rgbtRed+tmp[i][j+1].rgbtRed+tmp[i+1][j].rgbtRed+tmp[i+1][j+1].rgbtRed)/4);
                        }
                        else if (j < width) // Middle but not last pixel
                        {
                            image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue+tmp[i][j+1].rgbtBlue+tmp[i+1][j].rgbtBlue+tmp[i+1][j+1].rgbtBlue)+tmp[i][j-1].rgbtBlue+tmp[i+1][j-1].rgbtBlue)/6);
                            image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen+tmp[i][j+1].rgbtGreen+tmp[i+1][j].rgbtGreen+tmp[i+1][j+1].rgbtGreen)+tmp[i][j-1].rgbtGreen+tmp[i+1][j-1].rgbtGreen)/6);
                            image[i][j].rgbtRed = round((tmp[i][j].rgbtRed+tmp[i][j+1].rgbtRed+tmp[i+1][j].rgbtRed+tmp[i+1][j+1].rgbtRed)+tmp[i][j-1].rgbtRed+tmp[i+1][j-1].rgbtRed)/6);
                        }
                        else // Last Pixel on top row
                        {
                            image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue+tmp[i][j-1].rgbtBlue+tmp[i+1][j].rgbtBlue+tmp[i+1][j-1].rgbtBlue)/4);
                            image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen+tmp[i][j-1].rgbtGreen+tmp[i+1][j].rgbtGreen+tmp[i+1][j-1].rgbtGreen)/4);
                            image[i][j].rgbtRed = round((tmp[i][j].rgbtRed+tmp[i][j-1].rgbtRed+tmp[i+1][j].rgbtRed+tmp[i+1][j-1].rgbtRed)/4);
                        }
                    }
                if (i > 0 && i < height) // Middle Rows
                {
                    if (j == 0) // First Column
                    {
                        image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue+tmp[i][j+1].rgbtBlue+tmp[i+1][j].rgbtBlue+tmp[i+1][j+1].rgbtBlue+tmp[i-1][j].rgbtBlue+tmp[i-1][j+1].rgbtBlue))/6);
                        image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen+tmp[i][j+1].rgbtGreen+tmp[i+1][j].rgbtGreen+tmp[i+1][j+1].rgbtGreen+tmp[i-1][j].rgbtGreen+tmp[i-1][j+1].rgbtGreen))/6);
                        image[i][j].rgbtRed = round((tmp[i][j].rgbtRed+tmp[i][j+1].rgbtRed+tmp[i+1][j].rgbtRed+tmp[i+1][j+1].rgbtRed+tmp[i-1][j].rgbtRed+tmp[i-1][j+1].rgbtRed))/6);
                    }
                    else if (j < width) // Middle but not last pixel
                    {
                        image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue+tmp[i][j+1].rgbtBlue+tmp[i+1][j].rgbtBlue+tmp[i+1][j+1].rgbtBlue+tmp[i-1][j].rgbtBlue+tmp[i-1][j+1].rgbtBlue+tmp[i+1][j-1].rgbtBlue+tmp[i][j-1].rgbtBlue+tmp[i-1][j+1].rgbtBlue))/9);
                        image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen+tmp[i][j+1].rgbtGreen+tmp[i+1][j].rgbtGreen+tmp[i+1][j+1].rgbtGreen+tmp[i-1][j].rgbtGreen+tmp[i-1][j+1].rgbtGreen+tmp[i+1][j-1].rgbtGreen+tmp[i][j-1].rgbtGreen+tmp[i-1][j+1].rgbtGreen))/9);
                        image[i][j].rgbtRed = round((tmp[i][j].rgbtRed+tmp[i][j+1].rgbtRed+tmp[i+1][j].rgbtRed+tmp[i+1][j+1].rgbtRed+tmp[i-1][j].rgbtRed+tmp[i-1][j+1].rgbtRed+tmp[i+1][j-1].rgbtRed+tmp[i][j-1].rgbtRed+tmp[i-1][j+1].rgbtRed))/9);
                    }
                    else //last pixel
                    {
                        image[i][j].rgbtBlue = round((tmp[i][j].rgbtBlue+tmp[i+1][j].rgbtBlue+tmp[i-1][j].rgbtBlue+tmp[i-1][j-1].rgbtBlue+tmp[i+1][j-1].rgbtBlue+tmp[i][j-1].rgbtBlue))/6);
                        image[i][j].rgbtGreen = round((tmp[i][j].rgbtGreen+tmp[i+1][j].rgbtGreen+tmp[i-1][j].rgbtGreen+tmp[i-1][j-1].rgbtGreen+tmp[i+1][j-1].rgbtGreen+tmp[i][j-1].rgbtGreen))/6);
                        image[i][j].rgbtRed = round((tmp[i][j].rgbtRed+tmp[i+1][j].rgbtRed+tmp[i-1][j].rgbtRed+tmp[i-1][j-1].rgbtRed+tmp[i+1][j-1].rgbtRed+tmp[i][j-1].rgbtRed))/6);
                    }
                }
                if (i == height) // Last Row
                    if (j == 0) //First pixel
                    {

                    }
                    else if (j < width) //Middle Pixels
                    {

                    }
                    else //Last pixel
                    {

                    }
            }
        }
}
//When implementing the blur function, you might find that blurring one pixel ends up
//affecting the blur of another pixel. Perhaps create a copy of image (the function’s
//third argument) by declaring a new (two-dimensional) array with code like
//RGBTRIPLE copy[height][width]; and copying image into copy, pixel by pixel,
//with nested for loops? And then read pixels’ colors from copy but write
//(i.e., change) pixels’ colors in image?