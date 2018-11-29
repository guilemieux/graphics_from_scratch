#include <stdio.h>
#include "vector.h"

int main(void)
{
    Vector3d_t v = Vector3d_new(-2.0, 2.0, 1.0);
    Vector3d_t u = Vector3d_new(3.0, 1.0, -2.0);
    Vector3d_t w = Vector3d_add(v, u);

    Vector3d_print(w);
    printf("\n");

    Vector3d_free(v);
    Vector3d_free(u);
    Vector3d_free(w);

    return 0;
}