#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pixel.h"

#define MAX_COLOR 255
#define MAX_OPACITY 255

Pixel_t Pixel_new()
{
    return (Pixel_t) {
        .r = MAX_COLOR;
        .g = MAX_COLOR;
        .b = MAX_COLOR;
        .alpha = MAX_OPACITY;
    };
}

void Pixel_set_to_red(Pixel_t *p)
{
    p->r = MAX_COLOR;
    p->g = 0;
    p->b = 0;
}

void Pixel_set_to_green(Pixel_t *p)
{
    p->r = 0;
    p->g = MAX_COLOR;
    p->b = 0;
}

void Pixel_set_to_blue(Pixel_t *p)
{
    p->r = 0;
    p->g = 0;
    p->b = MAX_COLOR;
}

void Pixel_set_to_white(Pixel_t *p)
{
    p->r = 0;
    p->g = 0;
    p->b = 0;
}
