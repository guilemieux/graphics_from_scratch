#include <stdlib.h>
#include "camera.h"
#include "linalg.h"
#include "ray.h"

#define DEFAULT_POS VECTOR(1, 0, 0)
#define DEFAULT_DIR VECTOR(-1, 0, 0)
#define DEFAULT_RES 500
#define DEFAULT_PIX_SIZE 0.02
#define DEFAULT_FOCAL_LEN 1

struct sensor
{
    int x_res;
    int y_res;
    double pixel_size;
    Ray *rays;
};

struct Camera
{
    Vector pos;
    Vector dir;
    double foc_len;
    struct sensor s;
};

static int index_of(Camera_t cam, int row, int col)
{
    // TODO
    return 0;
}

static void compute_ray_at(Camera_t cam, int row, int col)
{
    // TODO
    return (Ray){};
}

static void compute_rays(Camera_t cam)
{
    int n_rows = cam->s.x_res;
    int n_cols = cam->s.y_res;

    // For each pixel in the sensor
    for (int row = 0; row < n_rows; row++)
    {
        for (int col = 0; col < n_cols; col++)
        {
            compute_ray_at(cam, row, col);
        }
    }
}

Camera_t camera_new()
{
    Camera_t cam = malloc(sizeof(struct Camera));
    cam->pos = DEFAULT_POS;
    cam->dir = DEFAULT_DIR;
    cam->foc_len = DEFAULT_FOCAL_LEN;

    cam->s.x_res = DEFAULT_RES;
    cam->s.y_res = DEFAULT_RES;
    cam->s.pixel_size = DEFAULT_PIX_SIZE;

    cam->s.rays = malloc(DEFAULT_RES * DEFAULT_RES * sizeof(Ray));
    compute_rays(cam);
    return cam;
}

void camera_del(Camera_t camera)
{
    free(camera->s.rays);
    free(camera);
}

Ray camera_get_ray_at(Camera_t camera, int row, int col)
{
    // TODO
    return (Ray){};
}
