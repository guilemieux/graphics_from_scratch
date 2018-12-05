#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

struct Vector2d_t {
    double x;
    double y;
};

struct Vector3d_t {
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

/* 2D VECTOR ***********************************/
Vector2d_t Vector2d_new(double x, double y)
{
    Vector2d_t v = malloc(sizeof(struct Vector2d_t));
    v->x = x;
    v->y = y;
    return v;
}

void Vector2d_free(Vector2d_t v)
{
    free(v);
}

void Vector2d_to_string(Vector2d_t v, char *s, size_t max_len)
{
    snprintf(s, max_len, "(%.3f, %.3f)", v->x, v->y);
}

Vector2d_t Vector2d_add(Vector2d_t u, Vector2d_t v)
{
    return Vector2d_new(u->x + v->x, u->y + v->y);
}

Vector2d_t Vector2d_unary_minus(Vector2d_t v)
{
    return Vector2d_new(-1 * v->x, -1 * v->y);
}

Vector2d_t Vector2d_scale(Vector2d_t v, double a)
{
    return Vector2d_new(a * v->x, a * v->y);
}

double Vector2d_norm(Vector2d_t v)
{
    return sqrt(v->x * v->x + v->y * v->y);
}

double Vector2d_dot_product(Vector2d_t a, Vector2d_t b)
{
    return a->x * b->x + a->y * b->y;
}

/* 3D VECTOR ***********************************/ 
Vector3d_t Vector3d_new(double x, double y, double z)
{
    Vector3d_t v = malloc(sizeof(struct Vector3d_t));
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

void Vector3d_free(Vector3d_t v)
{
    free(v);
}

void Vector3d_to_string(Vector3d_t v, char *s, size_t max_len)
{
    snprintf(s, max_len, "(%.3f, %.3f, %.3f)", v->x, v->y, v->z);
}

Vector3d_t Vector3d_add(Vector3d_t u, Vector3d_t v)
{
    return Vector3d_new(u->x + v->x, u->y + v->y, u->z + v->z);
}

Vector3d_t Vector3d_unary_minus(Vector3d_t v)
{
    return Vector3d_new(-1 * v->x, -1 * v->y, -1 * v->z);
}

Vector3d_t Vector3d_scale(Vector3d_t v, double a)
{
    return Vector3d_new(a * v->x, a * v->y, a * v->z);
}

double Vector3d_norm(Vector3d_t v)
{
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

double Vector3d_dot_product(Vector3d_t a, Vector3d_t b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}
