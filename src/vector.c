#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

struct Vector_t {
    double x;
    double y;
    double z;
};

/************************************************
 * HELPER METHODS
 ***********************************************/ 


/************************************************
 * INTERFACE IMPLEMENTATIONS
 ***********************************************/
Vector_t Vector_new(double x, double y, double z)
{
    Vector_t v = malloc(sizeof(struct Vector_t));
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

void Vector_free(Vector_t v)
{
    free(v);
}

void Vector_to_string(Vector_t v, char *s, size_t max_len)
{
    snprintf(s, max_len, "(%.3f, %.3f, %.3f)", v->x, v->y, v->z);
}

Vector_t Vector_add(Vector_t u, Vector_t v)
{
    return Vector_new(u->x + v->x, u->y + v->y, u->z + v->z);
}

Vector_t Vector_minus(Vector_t v)
{
    return Vector_new(-1 * v->x, -1 * v->y, -1 * v->z);
}

Vector_t Vector_scale(Vector_t v, double a)
{
    return Vector_new(a * v->x, a * v->y, a * v->z);
}

double Vector_norm(Vector_t v)
{
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

double Vector_dot(Vector_t a, Vector_t b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

Vector_t Vector_cross(Vector_t a, Vector_t b)
{
    double x = a->y * b->z - a->z * b->y;
    double y = a->z * b->x - a->x * b->z;
    double z = a->x * b->y - a->y * b->x;
    return Vector_new(x, y, z);
}
