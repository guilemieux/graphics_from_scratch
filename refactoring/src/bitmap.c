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
    int num_pixels;
    struct color *pixels;
};

static int get_pixel_index(Bitmap_t *bitmap, int row, int col)
{
    return bitmap->width * row + col;
}

Bitmap_t *new_bitmap(int width, int height)
{
    Bitmap_t *bitmap = malloc(sizeof(struct bitmap));
    bitmap->width = width;
    bitmap->height = height;
    bitmap->num_pixels = width * height;
    bitmap->pixels = malloc(bitmap->num_pixels * sizeof(struct color));
    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            bitmap_set_color_at(bitmap, get_color(WHITE), row, col);
    return bitmap;
}

void free_bitmap(Bitmap_t *bitmap)
{
    free(bitmap->pixels);
    free(bitmap);
}

int bitmap_width(Bitmap_t *bitmap)
{
    return bitmap->width;
}

int bitmap_height(Bitmap_t *bitmap)
{
    return bitmap->height;
}

struct color bitmap_get_color_at(Bitmap_t *bitmap, int row, int col)
{
    int pixel_index = get_pixel_index(bitmap, row, col);
    return bitmap->pixels[pixel_index];
}

void bitmap_set_color_at(Bitmap_t *bitmap, struct color c, int row, int col)
{
    int pixel_index = get_pixel_index(bitmap, row, col);
    bitmap->pixels[pixel_index] = c;
}
