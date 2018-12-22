#include <stdlib.h>
#include "camera.h"
#include "linalg.h"
#include "model.h"
#include "ray.h"
#include "surface.h"

#define SURFACES_INIT_SIZE 2

struct model
{
    struct
    {
        int len;
        int size;
        Surface_t *data;
    } surfaces;
    Camera_t cam;
};

Model_t model_new()
{
    Model_t model = malloc(sizeof(struct model));
    model->surfaces.len = 0;
    model->surfaces.size = SURFACES_INIT_SIZE;
    model->surfaces.data = malloc(model->surfaces.size * sizeof(Surface_t));
    model->cam = camera_new();
    return model;
}

void model_del(Model_t model)
{
    if (model->surfaces.size != 0)
        free(model->surfaces.data);
    camera_del(model->cam);
    free(model);
}

void model_add_surface(Model_t model, Surface_t surface)
{
    // Allocate memory for one surface
    if (model->surfaces.size == model->surfaces.len)
    {
        model->surfaces.data = realloc(
            model->surfaces.data,
            model->surfaces.size * 2 * sizeof(Surface_t));
        model->surfaces.size *= 2;
    }

    // Add surface to array
    model->surfaces.data[model->surfaces.len] = surface;
    model->surfaces.len++;
}

void take_picture(Model_t model, Bitmap_t bitmap)
{
    // Set bitmap dimentions based on camera sensor
    int w = model->cam.sensor.x_res;
    int h = model->cam.sensor.y_res;
    bitmap_set_dim(bitmap, w, h);

    // For each pixel in sensor
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            Ray r = camera_get_ray_at(model, row, col);
        }
    }
}
