#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define T Triangle_t

struct T {
    Vector_t a;
    Vector_t b;
    Vector_t c;
};

T Triangle_new(Vector_t a, Vector_t b, Vector_t c)
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
    Vector_t a = t->a;
    Vector_t b = t->b;
    Vector_t c = t->c;

    Vector_t minus_a = Vector_minus(a);
    Vector_t b_minus_a = Vector_add(b, minus_a);
    Vector_t c_minus_a = Vector_add(c, minus_a);
    Vector_t cross = Vector_cross(b_minus_a, c_minus_a);

    double area = 0.5 * Vector_norm(cross);

    Vector_free(minus_a);
    Vector_free(b_minus_a);
    Vector_free(c_minus_a);
    Vector_free(cross);
    
    return area;
}
