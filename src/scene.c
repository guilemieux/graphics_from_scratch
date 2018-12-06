#include <stdio.h> // tmp

#include <stdbool.h>
#include <stdlib.h>
#include "../includes/matrix.h"
#include "../includes/scene.h"
#include "../includes/triangle.h"
#include "../includes/vector.h"

#define INIT_SIZE 10

typedef struct ray {
    Vector_t pos;
    Vector_t dir;
} Ray_t;

typedef struct camera {
    int x_res;
    int y_res;
    double pixel_size;
    double focal_length;
} Camera_t;

struct Scene_t {
    Vector_t cam_pos;
    Vector_t cam_dir;
    Camera_t camera;
    int count;
    int size;
    Triangle_t *triangles;
};

/************************************************
 * HELPER METHODS
 ***********************************************/
Vector_t get_eye_pos(Scene_t s)
{
    Vector_t eye_dir_from_cam = Vector_neg(Vector_unit(s->cam_dir));
    Vector_t scale = Vector_scale(eye_dir_from_cam, s->camera.focal_length);
    return Vector_add(s->cam_pos, scale);
}

Vector_t get_pixel_pos(Scene_t s, int x, int y)
{
    // get u and v vectors that serve as a basis for camera
    Vector_t w = Vector_unit(Vector_neg(s->cam_dir));
    double u_x;
    if (w.x > 0) {
        u_x = 1;
    } else {
        u_x = -1;
    }
    Vector_t u = Vector_unit(Vector_new(0, 1, 0));
    Vector_t v = Vector_unit(Vector_cross(w, u));
    
    // get center pixel
    int x_center = s->camera.x_res / 2;
    int y_center = s->camera.y_res / 2;

    // get shift from middle
    double x_shift = (x - x_center) * s->camera.pixel_size;
    double y_shift = (y - y_center) * s->camera.pixel_size;
    Vector_t shift = Vector_add(
            Vector_scale(u, x_shift), Vector_scale(v, y_shift));
    return Vector_add(s->cam_pos, shift);
}

Ray_t get_ray(Scene_t s, Vector_t pixel_pos)
{
    Vector_t e = get_eye_pos(s);
    return (Ray_t) {
        .pos = e,
        .dir = Vector_add(pixel_pos, Vector_neg(e))
    };
}

bool ray_hits_triangle(Ray_t r, Triangle_t tri, double t0, double t1)
{
    Matrix_t A = Matrix_new();
    A.x[0][0] = tri.a.x - tri.b.x;
    A.x[0][1] = tri.a.x - tri.c.x;
    A.x[0][2] = r.dir.x;
    A.x[1][0] = tri.a.y - tri.b.y;
    A.x[1][1] = tri.a.y - tri.c.y;
    A.x[1][2] = r.dir.y;
    A.x[2][0] = tri.a.z - tri.b.z;
    A.x[2][1] = tri.a.z - tri.c.z;
    A.x[2][2] = r.dir.z;
    double det_A = Matrix_det(A);

    Matrix_t t_upper = A;
    t_upper.x[0][2] = tri.a.x - r.pos.x;
    t_upper.x[1][2] = tri.a.y - r.pos.y;
    t_upper.x[2][2] = tri.a.z - r.pos.z;
    double t = Matrix_det(t_upper) / det_A;
    if (t < t0 || t1 < t) return false;

    Matrix_t gamma_upper = A;
    gamma_upper.x[0][1] = tri.a.x - r.pos.x;
    gamma_upper.x[1][1] = tri.a.y - r.pos.y;
    gamma_upper.x[2][1] = tri.a.z - r.pos.z;
    double gamma = Matrix_det(gamma_upper) / det_A;
    if (gamma < 0 || 1 < gamma) return false;

    Matrix_t beta_upper = A;
    beta_upper.x[0][0] = tri.a.x - r.pos.x;
    beta_upper.x[1][0] = tri.a.y - r.pos.y;
    beta_upper.x[2][0] = tri.a.z - r.pos.z;
    double beta = Matrix_det(beta_upper) / det_A;
    if (beta < 0 || 1 < beta) return false;
    return true;
}

/************************************************
 * INTERFACE IMPLEMENTATION
 ***********************************************/
Scene_t Scene_new()
{
    Scene_t s = malloc(sizeof(struct Scene_t));
    s->cam_pos = Vector_scale(Vector_unit(Vector_new(1.0, 0.0, 0.0)), 10.0);
    s->cam_dir = Vector_unit(Vector_neg(s->cam_pos));
    s->camera = (Camera_t) {
        .x_res = 60,
        .y_res = 60,
        .pixel_size = 0.03,
        .focal_length = 100
    };
    s->count = 0;
    s->size = INIT_SIZE;
    s->triangles = malloc(INIT_SIZE * sizeof(struct triangle));
    return s;
}

void Scene_free(Scene_t s)
{
    free(s->triangles);
    free(s);
}

void Scene_add_triangle(Scene_t s, Triangle_t t)
{
    if (s->count == s->size) {
        s->size *= 2;
        s->triangles = realloc(s->triangles, s->size);
    }
    s->triangles[s->count] = t;
    s->count++;
}

void Scene_take_picture(Scene_t s)
{
    int n_rows = s->camera.x_res;
    int n_cols = s->camera.y_res;

    bool image[60][60];
    for (int i = 60 - 1; i >= 0; i--) {
        for (int j = 0; j < 60; j++) {
            image[i][j] = false;
        }
    }

    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols; col++) {
            Vector_t pixel_pos = get_pixel_pos(s, row, col);
            Ray_t r = get_ray(s, pixel_pos);

            // for each triangle
            for (int i = 0; i < s->count; i++) {
                Triangle_t tri = s->triangles[i];
                if (ray_hits_triangle(r, tri, 0, 1000)) {
                    image[row][col] = true;
                    break;
                }
            }
        }
    }

    for (int i = 60 - 1; i >= 0; i--) {
        for (int j = 0; j < 60; j++) {
            if (image[i][j]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
