#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "linalg.h"

bool vec_equal(Vector a, Vector b)
{
    return a.x == b.x && a.y == b.x && a.z == b.z;
}

Vector add_vec(Vector a, Vector b)
{
    return VECTOR(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector diff_vec(Vector a, Vector b)
{
    return VECTOR(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector neg_vec(Vector v)
{
    return scale_vec(-1, v);
}

Vector scale_vec(double c, Vector v)
{
    return VECTOR(c * v.x, c * v.y, c * v.z);
}

double norm(Vector v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double dot_product(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector cross_product(Vector a, Vector b)
{
    return VECTOR(a.y * b.z - a.z * b.y,
                  a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);
}

Vector unit_vec(Vector v)
{
    return scale_vec(1.0 / norm(v), v);
}
