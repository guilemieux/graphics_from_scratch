#include "color.h"

/* Bit mask for the hexadecimal representation of a color */
#define RED_MASK 0xFF0000
#define GREEN_MASK 0x00FF00
#define BLUE_MASK 0x0000FF

/* Number of bits required to shift the color data to the right location in the
   hexadecimal representation */
#define RED_SHIFT 16
#define GREEN_SHIFT 8
#define BLUE_SHIFT 0

static int hex_repr(struct color c)
{
    return (c.r << RED_SHIFT) | (c.g << GREEN_SHIFT) | (c.b << BLUE_SHIFT);
}

struct color rgb(unsigned char r, unsigned char g, unsigned char b)
{
    return (struct color){.r = r, .g = g, .b = b};
}

struct color get_color(int hex_color)
{
    unsigned char r = (RED_MASK & hex_color) >> RED_SHIFT;
    unsigned char g = (GREEN_MASK & hex_color) >> GREEN_SHIFT;
    unsigned char b = (BLUE_MASK & hex_color) >> BLUE_SHIFT;
    return rgb(r, g, b);
}

int compare_color(struct color c1, struct color c2)
{
    return hex_repr(c1) - hex_repr(c2);
}
