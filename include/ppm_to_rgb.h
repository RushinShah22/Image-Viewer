#ifndef PPM_TO_RGB_H
#define PPM_TO_RGB_H

typedef struct RGB
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
} RGB;

typedef struct Image
{
    int w;
    int h;
    int max_pixel_val;
    RGB **pixels;
} Image;

Image ppm_to_rgb(const char *);

#endif