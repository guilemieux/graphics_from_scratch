#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <stdbool.h>
#include "color.h"
#include "linalg.h"
#include "ray.h"

typedef Surface *Surface_t;

typedef struct
{
    Vector a;
    Vector b;
    Vector c;
} Triangle;

typedef struct
{
    double r;   // Radius
    Vector pos; // Position of the center
} Sphere;

extern Surface_t surface_new_triangle(Triangle t);
extern Surface_t surface_new_sphere(Sphere s);
extern void surface_free(Surface_t surface);
extern void surface_set_color(Surface_t surface, Color c);
extern bool surface_hits(Surface_t s, Ray r, double t0, double t1);

#endif
