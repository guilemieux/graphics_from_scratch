#include <stdlib.h>
#include "bitmap.h"
#include "color.h"

struct pixel
{
    char r;
    char g;
    char b;
    char a;
};

struct bitmap
{
    int width;
    int height;
    struct color *pixels;
};

static int get_pixel_index(Bitmap_t bitmap, int row, int col)
{
    return bitmap->width * row + col;
}

Bitmap_t new_bitmap()
{
    Bitmap_t bitmap = malloc(sizeof(struct bitmap));
    bitmap->width = 0;
    bitmap->height = 0;
    bitmap->pixels = NULL;
    return bitmap;
}

void free_bitmap(Bitmap_t bitmap)
{
    if (bitmap->pixels != NULL)
        free(bitmap->pixels);
    free(bitmap);
}

void bitmap_set_dim(Bitmap_t bitmap, int width, int height)
{
    if (bitmap->width == width && bitmap->height == height)
        return;

    if (bitmap->pixels == NULL)
        bitmap->pixels = malloc(width * height * sizeof(struct color));
    else
        bitmap->pixels = realloc(bitmap->pixels,
                                 width * height * sizeof(struct color));

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            bitmap_set_color_at(bitmap, get_color(WHITE), row, col);
}

int bitmap_width(Bitmap_t bitmap)
{
    return bitmap->width;
}

int bitmap_height(Bitmap_t bitmap)
{
    return bitmap->height;
}

struct color bitmap_get_color_at(Bitmap_t bitmap, int row, int col)
{
    int pixel_index = get_pixel_index(bitmap, row, col);
    return bitmap->pixels[pixel_index];
}

void bitmap_set_color_at(Bitmap_t bitmap, struct color c, int row, int col)
{
    int pixel_index = get_pixel_index(bitmap, row, col);
    bitmap->pixels[pixel_index] = c;
}
