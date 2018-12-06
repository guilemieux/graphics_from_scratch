#include "triangle.h"

#ifndef _SCENE_H_
#define _SCENE_H_

typedef struct Scene_t *Scene_t;

extern Scene_t Scene_new();
extern void Scene_free(Scene_t s);
extern void Scene_add_triangle(Scene_t s, Triangle_t t);
extern void Scene_set_camera_pos(Scene_t s, Vector_t pos);
extern void Scene_take_picture(Scene_t s);

#endif
