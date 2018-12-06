#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/image.h"
#include "../includes/pixel.h"

struct Image_t {
    int width;
    int height;
    Pixel_t **pixels;
};

/************************************************
 * HELPER METHODS
 ***********************************************/
bool cell_exists(Image_t image, int row, int col)
{
    return row < image->height && col < image->width; 
}

/************************************************
 * INTERFACE IMPLEMENTATIONS
 ***********************************************/
Image_t Image_new(int width, int height)
{
    Image_t image = malloc(sizeof(struct Image_t));
    image->width = width;
    image->height = height;
    image->pixels = malloc(height * sizeof(Pixel_t *));
    for (int row = 0; row < height; row++) {
        image->pixels[row] = malloc(width * sizeof(Pixel_t));
        for (int col = 0; col < width; col++) {
            image->pixels[row][col] = Pixel_new();
        }
    }
    return image;
}

void Image_free(Image_t image)
{
    for (int row = 0; row < image->height; row++) {
        free(image->pixels[row]);
    }
    free(image->pixels);
}

int Image_get_width(Image_t image)
{
    return image->width;
}

int Image_get_height(Image_t image)
{
    return image->height;
}

Pixel_t Image_get_pixel(Image_t image, int row, int col)
{
    assert(cell_exists(image, row, col));
    return image->pixels[row][col];
}

void Image_set_pixel(Image_t image, Pixel_t p, int row, int col)
{
    assert(cell_exists(image, row, col));
    image->pixels[row][col] = p;
}
