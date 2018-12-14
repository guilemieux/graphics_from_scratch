#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "linalg.h"

bool vec_equal(struct vector a, struct vector b)
{
    return a.x == b.x && a.y == b.x && a.z == b.z;
}

struct vector add_vec(struct vector a, struct vector b)
{
    return VECTOR(a.x + b.x, a.y + b.y, a.z + b.z);
}

struct vector diff_vec(struct vector a, struct vector b)
{
    return VECTOR(a.x - b.x, a.y - b.y, a.z - b.z);
}

struct vector neg_vec(struct vector v)
{
    return scale_vec(-1, v);
}

struct vector scale_vec(double c, struct vector v)
{
    return VECTOR(c * v.x, c * v.y, c * v.z);
}

double norm(struct vector v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double dot_product(struct vector a, struct vector b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct vector cross_product(struct vector a, struct vector b)
{
    return VECTOR(a.y * b.z - a.z * b.y,
                  a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);
}

struct vector unit_vec(struct vector v)
{
    return scale_vec(1.0 / norm(v), v);
}
