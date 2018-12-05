/*
 * pixel.h
 * 
 * Author: Guillaume Lemieux
 */
#include <stdint.h>

#ifndef PIXEL_INCLUDED
#define PIXEL_INCLUDED

#define T Pixel_t

typedef struct T *T;

extern T Pixel_new();
extern void Pixel_free(T pixel);
extern uint8_t Pixel_get_red(T pixel);
extern uint8_t Pixel_get_green(T pixel);
extern uint8_t Pixel_get_blue(T pixel);
extern uint8_t Pixel_get_alpha(T pixel);
extern void Pixel_set_red(T pixel, uint8_t red);
extern void Pixel_set_green(T pixel, uint8_t green);
extern void Pixel_set_blue(T pixel, uint8_t blue);
extern void Pixel_set_alpha(T pixel, uint8_t alpha);
extern void Pixel_set_to_red(T pixel);
extern void Pixel_set_to_green(T pixel);
extern void Pixel_set_to_blue(T pixel);
extern void Pixel_set_to_white(T pixel);
extern void Pixel_print(T pixel);

#undef T
#endif