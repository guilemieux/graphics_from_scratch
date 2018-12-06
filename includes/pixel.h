#include <stdint.h>

#ifndef _PIXEL_H_
#define _PIXEL_H_

typedef struct pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t alpha;
} Pixel_t;

extern Pixel_t Pixel_new();
extern void Pixel_set_to_red(Pixel_t *pixel);
extern void Pixel_set_to_green(Pixel_t *pixel);
extern void Pixel_set_to_blue(Pixel_t *pixel);
extern void Pixel_set_to_white(Pixel_t *pixel);

#endif