#include "vector.h"

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

typedef struct triangle {
    Vector_t a;
    Vector_t b;
    Vector_t c;
} Triangle_t;

extern Triangle_t Triangle_new(Vector_t a, Vector_t b, Vector_t c);
extern double Triangle_area(Triangle_t t);

#endif
