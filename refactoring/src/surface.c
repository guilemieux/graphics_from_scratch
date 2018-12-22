#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "surface.h"
#include "color.h"
#include "linalg.h"

typedef enum
{
    TRIANGLE,
    SPHERE
} SurfaceType;

typedef struct
{
    SurfaceType type;
    Color color;
    void *data;
} Surface;

static bool hits_triangle(Triangle t, Ray r, double t0, double t1)
{
    Matrix A;
    A[0][0] = t.a.x - t.b.x;
    A[0][1] = t.a.x - t.c.x;
    A[0][2] = r.dir.x;
    A[1][0] = t.a.y - t.b.y;
    A[1][1] = t.a.y - t.c.y;
    A[1][2] = r.dir.y;
    A[2][0] = t.a.z - t.b.z;
    A[2][1] = t.a.z - t.c.z;
    A[2][2] = r.dir.z;
    double det_A = det(A);

    Matrix t_upper;
    matrix_cpy(t_upper, A);
    t_upper[0][2] = t.a.x - r.pos.x;
    t_upper[1][2] = t.a.y - r.pos.y;
    t_upper[2][2] = t.a.z - r.pos.z;
    double dist = det(t_upper) / det_A;
    if (dist < t0 || t1 < dist)
        return false;

    Matrix gamma_upper;
    matrix_cpy(gamma_upper, A);
    gamma_upper[0][1] = t.a.x - r.pos.x;
    gamma_upper[1][1] = t.a.y - r.pos.y;
    gamma_upper[2][1] = t.a.z - r.pos.z;
    double gamma = det(gamma_upper) / det_A;
    if (gamma < 0 || 1 < gamma)
        return false;

    Matrix beta_upper;
    matrix_cpy(beta_upper, A);
    beta_upper[0][0] = t.a.x - r.pos.x;
    beta_upper[1][0] = t.a.y - r.pos.y;
    beta_upper[2][0] = t.a.z - r.pos.z;
    double beta = det(beta_upper) / det_A;
    return (0 < beta && beta <= 1 - gamma);
}

static bool hits_sphere(Sphere sph, Ray r, double t0, double t1)
{
    Vector d = unit_vec(r.dir);
    Vector e = r.pos;
    Vector center = sph.pos;

    double a = dot_product(d, d);
    double b = dot_product(scale_vec(2, d), diff_vec(e, center));
    double c = dot_product(diff_vec(e, center), diff_vec(e, center)) - sph.r;

    double discr = b * b - 4 * a * c;
    return discr >= 0;
}

Surface_t surface_new_triangle(Triangle triangle)
{
    Surface_t surface = malloc(sizeof(Surface));
    surface->type = TRIANGLE;
    surface->color = get_color(BLACK);
    surface->data = malloc(sizeof(Triangle));
    *(surface->data) = triangle;
    return surface;
}

Surface_t surface_new_sphere(Sphere sphere)
{
    Surface_t s = malloc(sizeof(Surface));
    s->type = SPHERE;
    s->color = get_color(BLACK);
    s->data = malloc(sizeof(Sphere));
    *(s->data) = sphere;
    return s;
}

void surface_free(Surface_t surface)
{
    free(surface->data);
    free(surface);
}

void surface_set_color(Surface_t surface, Color c)
{
    surface->color = c;
}

bool surface_hits(Surface_t s, Ray r, double t0, double t1)
{
    switch (s->type)
    {
    case TRIANGLE:
        Triangle t = (Triangle)s->data;
        return hits_triangle(t, r, t0, t1);
    case SPHERE:
        Sphere sph = (Sphere)s->data;
        return hits_sphere(sph, r, t0, t1);
    }
    return false;
}
