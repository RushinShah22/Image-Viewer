#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "ppm_to_rgb.h"

int main()
{
    Image image = ppm_to_rgb("bitcoin.ppm");
    int w = image.w;
    int h = image.h;
    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);

    SDL_Event e;
    bool quit = false;
    if (w == -1)
    {
        quit = true;
    }
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
        Uint8 r;
        Uint8 g;
        Uint8 b;
        SDL_Rect *rect;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                r = image.pixels[i][j].r;
                g = image.pixels[i][j].g;
                b = image.pixels[i][j].b;
                Uint32 color = SDL_MapRGB(psurface->format, r, g, b);
                rect = &(SDL_Rect){j, i, 1, 1};
                SDL_FillRect(psurface, rect, color);
            }
        }
        SDL_UpdateWindowSurface(pwindow);
    }

    return 0;
}