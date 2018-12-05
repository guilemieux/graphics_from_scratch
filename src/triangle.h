#include "vector.h"

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#define T Triangle_t

typedef struct T *T;

extern T Triangle_new(Vector_t a, Vector_t b, Vector_t c);
extern void Triangle_free(T t);
extern double Triangle_area(T t);

#undef T

#endif
