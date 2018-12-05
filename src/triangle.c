#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define T Triangle_t

struct T {
    Vector3d_t a;
    Vector3d_t b;
    Vector3d_t c;
};

T Triangle_new(Vector3d_t a, Vector2d_t b, Vector2d_t c)
{
    T t = malloc(sizeof(struct T));
    if (t == NULL) {
        perror("Error: Cannot allocate memory for triangle");
        exit(EXIT_FAILURE);
    }
    t->a = a;
    t->b = b;
    t->c = c;
    return t;
}

void Triangle_free(T t)
{
    free(t);
}

double Triangle_area(T t)
{
    return 0.0;
}
