#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "bitmap.h"
#include "pixel.h"

#define T Bitmap_t

struct T {
    uint16_t width;
    uint16_t height;
    Pixel_t **pixels;
};

/************************************************
 * HELPER METHODS
 ***********************************************/

bool cell_exists(T bm, uint16_t row, uint16_t col)
{
    return row < bm->height && col < bm->width; 
}

/************************************************
 * INTERFACE IMPLEMENTATIONS
 ***********************************************/

T Bitmap_new(uint16_t width, uint16_t height)
{
    T bm = malloc(sizeof(T));
    bm->width = width;
    bm->height = height;
    bm->pixels = malloc(height * sizeof(Pixel_t *));
    for (uint16_t row = 0; row < height; row++) {
        bm->pixels[row] = malloc(width * sizeof(Pixel_t));
        for (uint16_t col = 0; col < width; col++) {
            bm->pixels[row][col] = Pixel_new();
        }
    }
    return bm;
}

void Bitmap_free(T bitmap)
{
    for (uint16_t row = 0; row < bitmap->height; row++) {
        for (uint16_t col = 0; col < bitmap->width; col++) {
            Pixel_free(bitmap->pixels[row][col]);
        }
        free(bitmap->pixels[row]);
    }
    free(bitmap->pixels);
}

uint16_t Bitmap_get_width(T bitmap)
{
    return bitmap->width;
}

uint16_t Bitmap_get_height(T bitmap)
{
    return bitmap->height;
}

Pixel_t Bitmap_get_pixel(T bitmap, uint16_t row, uint16_t col)
{
    assert(cell_exists(bitmap, row, col));
    return bitmap->pixels[row][col];
}

void Bitmap_set_pixel(T bm, Pixel_t p, uint16_t row, uint16_t col)
{
    assert(cell_exists(bm, row, col));
    Pixel_t target = bm->pixels[row][col];
    Pixel_set_red(target, Pixel_get_red(p));
    Pixel_set_green(target, Pixel_get_green(p));
    Pixel_set_blue(target, Pixel_get_blue(p));
    Pixel_set_alpha(target, Pixel_get_alpha(p));
}
