#include "linalg.h"

// [ [a,b,c],
//   [d,e,f],
//   [g,h,i] ]
double det(struct matrix m)
{
    double a = m.x[0][0], b = m.x[0][1], c = m.x[0][2],
           d = m.x[1][0], e = m.x[1][1], f = m.x[1][2],
           g = m.x[2][0], h = m.x[2][1], i = m.x[2][2];
    double ei_minus_fh = e * i - f * h;
    double di_minus_fg = d * i - f * g;
    double dh_minus_eg = d * h - e * g;
    return a * ei_minus_fh - b * di_minus_fg + c * dh_minus_eg;
}
