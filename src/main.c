#include <stdio.h>
#include "../includes/bmp.h"
#include "../includes/image.h"
#include "../includes/scene.h"
#include "../includes/triangle.h"
#include "../includes/vector.h"

#define RESOLUTION 512

int main(void)
{
    Scene_t s = Scene_new();

    // front
    Scene_add_triangle(s, Triangle_new(
        Vector_new(0.5, -0.49, 0.49),
        Vector_new(0.5, 0.49, -0.49),
        Vector_new(0.5, 0.49, 0.49)
    ));
    Scene_add_triangle(s, Triangle_new(
        Vector_new(0.5, 0.5, -0.5),
        Vector_new(0.5, -0.5, 0.5),
        Vector_new(0.5, -0.5, -0.5)
    ));

    // side
    Scene_add_triangle(s, Triangle_new(
        Vector_new(-0.5, 0.5, 0.5),
        Vector_new(0.5, 0.5, -0.5),
        Vector_new(0.5, 0.5, 0.5)
    ));
    Scene_add_triangle(s, Triangle_new(
        Vector_new(0.49, 0.5, -0.49),
        Vector_new(-0.49, 0.5, 0.49),
        Vector_new(-0.49, 0.5, -0.49)
    ));
    
    // top
    Scene_add_triangle(s, Triangle_new(
        Vector_new(-0.5, 0.49, 0.5),
        Vector_new(0.5, -0.5, 0.5),
        Vector_new(0.49, 0.49, 0.5)
    ));
    Scene_add_triangle(s, Triangle_new(
        Vector_new(0.5, -0.5, 0.5),
        Vector_new(-0.5, 0.5, 0.5),
        Vector_new(-0.5, -0.5, 0.5)
    ));


    Image_t img = Image_new(RESOLUTION, RESOLUTION);
    Scene_set_camera_res(s, RESOLUTION, RESOLUTION);
    Scene_take_picture(s, img);
    save_to_bmp(img, "frame1.bmp");
    Image_free(img);

    Scene_free(s);
    return 0;
}
