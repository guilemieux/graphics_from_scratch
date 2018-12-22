#ifndef _MODEL_H_
#define _MODEL_H_

#include "bitmap.h"
#include "surface.h"

typedef struct model *Model_t;

extern Model_t model_new();
extern void model_del(Model_t model);
extern void model_add_surface(Model_t model, Surface_t t);
extern void take_picture(Model_t model, Bitmap_t bitmap);

#endif
