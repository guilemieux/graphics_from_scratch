#ifndef _BITMAP_H_
#define _BITMAP_H_

#include "color.h"

typedef struct bitmap *Bitmap_t;

extern Bitmap_t new_bitmap();
extern void free_bitmap(Bitmap_t bitmap);
extern void bitmap_set_dim(Bitmap_t bitmap, int width, int height);
extern int bitmap_width(Bitmap_t bitmap);
extern int bitmap_height(Bitmap_t bitmap);
extern Color bitmap_get_color_at(Bitmap_t bitmap, int row, int col);
extern void bitmap_set_color_at(Bitmap_t bitmap, struct color c, int row, int col);

extern void save_to_bmp(Bitmap_t bitmap, const char *file_name);

#endif
