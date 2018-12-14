#ifndef _LINALG_H_
#define _LINALG_H_

#include <stdbool.h>

#define MATRIX_DIM 3

#define VECTOR(a, b, c) \
    (struct vector) { .x = a, .y = b, .z = c }

struct vector
{
    double x;
    double y;
    double z;
};

struct matrix
{
    double x[MATRIX_DIM][MATRIX_DIM];
};

extern bool vec_equal(struct vector a, struct vector b);
extern struct vector add_vec(struct vector a, struct vector b);
extern struct vector diff_vec(struct vector a, struct vector b);
extern struct vector neg_vec(struct vector v);
extern struct vector scale_vec(double c, struct vector v);
extern double norm(struct vector v);
extern double dot_product(struct vector a, struct vector b);
extern struct vector cross_product(struct vector a, struct vector b);
extern struct vector unit_vec(struct vector v);

extern double det(struct matrix m);

#endif
