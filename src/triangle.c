#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"
#include "vector.h"

Triangle_t Triangle_new(Vector_t a, Vector_t b, Vector_t c)
{
    return (Triangle_t) {
        .a = a,
        .b = b,
        .c = c
    };
}

double Triangle_area(Triangle_t t)
{
    Vector_t b_minus_a = Vector_add(t.b, Vector_neg(t.a));
    Vector_t c_minus_a = Vector_add(t.c, Vector_neg(t.a));
    return 0.5 * Vector_norm(Vector_cross(b_minus_a, c_minus_a));
}
