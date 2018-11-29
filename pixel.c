#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pixel.h"

#define T Pixel_t
#define MAX_COLOR 255
#define MAX_OPACITY 255

struct T {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

/************************************************
 * HELPER METHODS
 ***********************************************/ 

/* Set the color of a pixel */
void set_color(T p, uint8_t r, uint8_t g, uint8_t b)
{
    p->red = r;
    p->green = g;
    p->blue = b;
}

/* Set the color and the transparency of a pixel */
void set_color_and_alpha(T p, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    p->red = r;
    p->green = g;
    p->blue = b;
    p->alpha = a;
}


/************************************************
 * INTERFACE IMPLEMENTATIONS
 ***********************************************/
T Pixel_new()
{
    T p = malloc(sizeof(T));
    set_color_and_alpha(p, MAX_COLOR, MAX_COLOR, MAX_COLOR, MAX_OPACITY);
    return p;
}

void Pixel_free(T pixel)
{
    free(pixel);
}

uint8_t Pixel_get_red(T pixel)
{
    return pixel->red;
}

uint8_t Pixel_get_green(T pixel)
{
    return pixel->green;
}

uint8_t Pixel_get_blue(T pixel)
{
    return pixel->blue;
}

uint8_t Pixel_get_alpha(T pixel)
{
    return pixel->alpha;
}

void Pixel_set_red(T pixel, uint8_t red)
{
    pixel->red = red;
}

void Pixel_set_green(T pixel, uint8_t green)
{
    pixel->green = green;
}

void Pixel_set_blue(T pixel, uint8_t blue)
{
    pixel->blue = blue;
}

void Pixel_set_alpha(T pixel, uint8_t alpha)
{
    pixel->alpha = alpha;
}

void Pixel_set_to_red(T pixel)
{
    set_color(pixel, MAX_COLOR, 0, 0);
}

void Pixel_set_to_green(T pixel)
{
    set_color(pixel, 0, MAX_COLOR, 0);
}

void Pixel_set_to_blue(T pixel)
{
    set_color(pixel, 0, 0, MAX_COLOR);
}

void Pixel_set_to_white(T pixel)
{
    set_color(pixel, MAX_COLOR, MAX_COLOR, MAX_COLOR);
}

void Pixel_print(T pixel)
{
    printf("(r: %d, g: %d, b: %d, a: %d)", pixel->red, pixel->green, pixel->blue, pixel->alpha);
}
