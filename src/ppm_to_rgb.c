#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>
#include "ppm_to_rgb.h"

Image ppm_to_rgb(const char *filename)
{
    FILE *f = fopen(filename, "r");
    RGB **image = NULL;
    if (f == NULL)
    {
        fprintf(stderr, "Error opening file %s", filename);
        return (Image){-1, -1, -1, image};
    }
    char buf[100];
    // Magic number
    fgets(buf, sizeof(buf), f);

    // comments
    fgets(buf, sizeof(buf), f);
    // dimensions
    fgets(buf, sizeof(buf), f);
    int max_pixel_val = atoi(buf);

    int dim[] = {0, 0};
    char digit[10];
    int idx = 0;
    int dim_idx = 0;
    for (int i = 0; i < 100; i++)
    {
        if (buf[i] >= '0' && buf[i] <= '9')
        {
            digit[idx] = buf[i];
            idx++;
        }
        if ((buf[i] < '0' || buf[i] > '9') && idx != 0)
        {
            dim[dim_idx] = atoi(digit);
            dim_idx++;
            idx = 0;
        }
    }
    // max pixel value;
    fgets(buf, sizeof buf, f);
    image = (RGB **)malloc(sizeof(RGB *) * dim[1]);
    for (int i = 0; i < dim[1]; i++)
    {
        image[i] = (RGB *)malloc(sizeof(RGB) * dim[0]);
    }
    for (int i = 0; i < dim[1]; i++)
    {
        int idx_val = 0;
        int val[3];
        char buf[10000];
        fgets(buf, sizeof(buf), f);
        int buf_idx = 0;

        for (int j = 0; j < dim[0]; j++)
        {
            char digit[10];
            int idx = 0;
            while (buf_idx < 1000 && idx_val != 3)
            {

                if (buf[buf_idx] >= '0' && buf[buf_idx] <= '9')
                {
                    digit[idx] = buf[buf_idx];
                    idx++;
                }
                else if (idx != 0)
                {
                    char formatted_digit[idx + 1];
                    for (int k = 0; k < idx; k++)
                        formatted_digit[k] = digit[k];
                    formatted_digit[idx] = '\0';

                    val[idx_val] = atoi(formatted_digit);
                    idx_val++;
                    idx = 0;
                }
                if (buf[buf_idx] == '\n')
                {
                    break;
                }
                buf_idx++;
            }
            if (idx_val != 3)
            {
                fgets(buf, sizeof buf, f);
                buf_idx = 0;
                j--;
                continue;
            }
            else
            {
                idx_val = 0;
            }
            image[i][j] = (RGB){val[0], val[1], val[2]};
        }
    }
    fclose(f);
    return (Image){dim[0], dim[1], max_pixel_val, image};
}