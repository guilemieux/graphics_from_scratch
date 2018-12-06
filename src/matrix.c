#include "../includes/matrix.h"

Matrix_t Matrix_new()
{
    Matrix_t m;
    for (int row = 0; row < MATRIX_DIM; row++) {
        for (int col = 0; col < MATRIX_DIM; col++) {
            m.x[row][col] = 0;
        }
    }
    return m;
}

// [ [a,b,c],
//   [d,e,f],
//   [g,h,i] ]
double Matrix_det(Matrix_t m)
{
    double a = m.x[0][0], b = m.x[0][1], c = m.x[0][2],
           d = m.x[1][0], e = m.x[1][1], f = m.x[1][2],
           g = m.x[2][0], h = m.x[2][1], i = m.x[2][2];
    double ei_minus_fh = e * i - f * h;
    double di_minus_fg = d * i - f * g;
    double dh_minus_eg = d * h - e * g;
    return a * ei_minus_fh - b * di_minus_fg + c * dh_minus_eg;
}
