#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "pixel.h"

#define T Image_t

typedef struct T *T;

extern T Image_new(int width, int height);
extern void Image_free(T image);
extern int Image_get_width(T image);
extern int Image_get_height(T image);
extern Pixel_t Image_get_pixel(T image, int row, int col);
extern void Image_set_pixel(T image, Pixel_t pixel, int row, int col);

#undef T

#endif
