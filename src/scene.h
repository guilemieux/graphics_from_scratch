#include "triangle.h"

#ifndef _SCENE_H_
#define _SCENE_H_

#define T Scene_t

typedef struct T *T;

extern T Scene_new();
extern void Scene_free(T t);
extern void Scene_add_triangle(Triangle_t t);
extern void Scene_remove_triangle(Triangle_t t);

#undef T

#endif
