#ifndef _LINALG_H_
#define _LINALG_H_

#include <stdbool.h>

#define MATRIX_DIM 3

#define VECTOR(x, y, z) \
    (Vector) { x, y, z }

typedef struct vector
{
    double x;
    double y;
    double z;
} Vector;

typedef double Matrix[MATRIX_DIM][MATRIX_DIM];

extern bool vec_equal(Vector a, Vector b);
extern Vector add_vec(Vector a, Vector b);
extern Vector diff_vec(Vector a, Vector b);
extern Vector neg_vec(Vector v);
extern Vector scale_vec(double c, Vector v);
extern double norm(Vector v);
extern double dot_product(Vector a, Vector b);
extern Vector cross_product(Vector a, Vector b);
extern Vector unit_vec(Vector v);

extern double det(Matrix m);
extern void matrix_cpy(Matrix dest, Matrix src);

#endif
