#include "helpers.h"
#include <math.h>

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            float average =
                (image[j][i].rgbtBlue + image[j][i].rgbtRed + image[j][i].rgbtGreen) / 3.0;
            average = round(average);
            image[j][i].rgbtBlue = image[j][i].rgbtGreen = image[j][i].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            double sepiared = image[j][i].rgbtBlue * 0.189 + image[j][i].rgbtGreen * 0.769 +
                              image[j][i].rgbtRed * 0.393;

            double sepiablue = image[j][i].rgbtBlue * 0.131 + image[j][i].rgbtGreen * 0.534 +
                               image[j][i].rgbtRed * 0.272;

            double sepiagreen = image[j][i].rgbtBlue * 0.168 + image[j][i].rgbtGreen * 0.686 +
                                image[j][i].rgbtRed * 0.349;
            image[j][i].rgbtRed = round(sepiared);
            image[j][i].rgbtBlue = round(sepiablue);
            image[j][i].rgbtGreen = round(sepiagreen);

            if (round(sepiared) > 255)
            {
                image[j][i].rgbtRed = 255;
            }
            if (round(sepiagreen) > 255)
            {
                image[j][i].rgbtGreen = 255;
            }
            if (round(sepiablue) > 255)
            {
                image[j][i].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - j - 1]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    {
        RGBTRIPLE copy[height][width];

        // Copy the original image to work from
        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                copy[j][i] = image[j][i];
            }
        }

        // Apply blur
        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                int redSum = 0, greenSum = 0, blueSum = 0;
                int count = 0;

                // Loop over neighboring pixels (including self)
                for (int dj = -1; dj <= 1; dj++)
                {
                    for (int di = -1; di <= 1; di++)
                    {
                        int nj = j + dj;
                        int ni = i + di;

                        // Check boundaries
                        if (nj >= 0 && nj < height && ni >= 0 && ni < width)
                        {
                            redSum += copy[nj][ni].rgbtRed;
                            greenSum += copy[nj][ni].rgbtGreen;
                            blueSum += copy[nj][ni].rgbtBlue;
                            count++;
                        }
                    }
                }

                image[j][i].rgbtRed = round((float) redSum / count);
                image[j][i].rgbtGreen = round((float) greenSum / count);
                image[j][i].rgbtBlue = round((float) blueSum / count);
            }
        }
    }

    return;
}
