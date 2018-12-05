/*
 * bitmap.h
 * 
 * Author: Guillaume Lemieux
 */
#include <stdint.h>
#include "pixel.h"

#ifndef BITMAP_H
#define BITMAP_H

#define T Bitmap_t

typedef struct T *T;

extern T Bitmap_new(uint16_t width, uint16_t height);
extern void Bitmap_free(T bitmap);
extern uint16_t Bitmap_get_width(T bitmap);
extern uint16_t Bitmap_get_height(T bitmap);
extern Pixel_t Bitmap_get_pixel(T bitmap, uint16_t row, uint16_t col);
extern void Bitmap_set_pixel(T bitmap, Pixel_t pixel, uint16_t row, uint16_t col);

#undef T

#endif