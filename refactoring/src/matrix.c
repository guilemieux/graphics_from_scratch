#include <string.h>
#include "linalg.h"

// [ [a,b,c],
//   [d,e,f],
//   [g,h,i] ]
double det(Matrix m)
{
    double a = m[0][0], b = m[0][1], c = m[0][2],
           d = m[1][0], e = m[1][1], f = m[1][2],
           g = m[2][0], h = m[2][1], i = m[2][2];
    double ei_minus_fh = e * i - f * h;
    double di_minus_fg = d * i - f * g;
    double dh_minus_eg = d * h - e * g;
    return a * ei_minus_fh - b * di_minus_fg + c * dh_minus_eg;
}

void matrix_cpy(Matrix dest, Matrix src)
{
    memcpy(dest, src, MATRIX_DIM * MATRIX_DIM * sizeof(double));
}
