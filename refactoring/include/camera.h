#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "linalg.h"
#include "ray.h"

typedef struct Camera *Camera_t;

extern Camera_t camera_new();
extern void camera_del(Camera_t camera);
extern Ray camera_get_ray_at(Camera_t camera, int row, int col);

#endif
