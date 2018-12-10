#include "../includes/color.h"

#define RED_MASK   0xFF0000
#define GREEN_MASK 0x00FF00
#define BLUE_MASK  0x0000FF
#define RED_SHIFT   16
#define GREEN_SHIFT 8
#define BLUE_SHIFT  0

static int get_hex_representation(struct color c)
{
    return (c.r << RED_SHIFT) & (c.g << GREEN_SHIFT) & (c.b << BLUE_SHIFT);
}

struct color get_color(int hex_color)
{
    return RGB(
        (RED_MASK & hex_color) >> RED_SHIFT,
        (GREEN_MASK & hex_color) >> GREEN_SHIFT,
        BLUE_MASK & hex_color >> BLUE_SHIFT
    );
}

int compare_color(struct color c1, struct color c2)
{
    int c1_hex = get_hex_representation(c1);
    int c2_hex = get_hex_representation(c2);
    return c1_hex - c2_hex;
}
