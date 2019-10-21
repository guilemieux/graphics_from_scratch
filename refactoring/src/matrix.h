#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MATRIX_DIM 3

typedef struct matrix {
    double x[MATRIX_DIM][MATRIX_DIM];
} Matrix_t;

extern Matrix_t Matrix_new();
extern double Matrix_det(Matrix_t m);

#endif
