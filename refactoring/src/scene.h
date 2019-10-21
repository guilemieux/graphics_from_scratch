#include "image.h"
#include "triangle.h"

#ifndef _SCENE_H_
#define _SCENE_H_

typedef struct Scene_t *Scene_t;

extern Scene_t Scene_new();
extern void Scene_free(Scene_t s);
extern void Scene_add_triangle(Scene_t s, Triangle_t t);
extern void Scene_set_camera_pos(Scene_t s, Vector_t pos);
extern void Scene_set_camera_dir(Scene_t s, Vector_t dir);
extern void Scene_set_camera_res(Scene_t s, int x_res, int y_res);
extern void Scene_set_camera_sensor_size(Scene_t s, double size);
extern void Scene_take_picture(Scene_t s, Image_t img);

#endif
