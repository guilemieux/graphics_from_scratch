#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../includes/vector.h"

Vector_t Vector_new(double x, double y, double z)
{
    return (Vector_t) { .x = x, .y = y, .z = z};
}

void Vector_to_string(Vector_t v, char *s, size_t max_len)
{
    snprintf(s, max_len, "(%.3f, %.3f, %.3f)", v.x, v.y, v.z);
}

Vector_t Vector_add(Vector_t a, Vector_t b)
{
    return (Vector_t) {
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
}

Vector_t Vector_neg(Vector_t v)
{
    return (Vector_t) {
        .x = -1 * v.x,
        .y = -1 * v.y,
        .z = -1 * v.z
    };
}

Vector_t Vector_scale(Vector_t v, double a)
{
    return (Vector_t) {
        .x = a * v.x,
        .y = a * v.y,
        .z = a * v.z
    };
}

double Vector_norm(Vector_t v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double Vector_dot(Vector_t a, Vector_t b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector_t Vector_cross(Vector_t a, Vector_t b)
{
    return (Vector_t) {
        .x = a.y * b.z - a.z * b.y,
        .y = a.z * b.x - a.x * b.z,
        .z = a.x * b.y - a.y * b.x,
    };
}

Vector_t Vector_unit(Vector_t v)
{
    return Vector_scale(v, 1.0 / Vector_norm(v));
}
