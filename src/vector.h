/*
 * vector.h
 * Guillaume Lemieux
 */
#ifndef _VECTOR_H_
#define _VECTOR_H_

/* Recomended size of the buffer for the to_string methods */
#define VEC_TO_STRING_LEN 64

typedef struct vector {
    double x;
    double y;
    double z;
} Vector_t;

extern Vector_t Vector_new(double x, double y, double z);

/* Puts a representation of a 3d vector in a string. The format of the 
 * output string is "(-1.234, 5.678, -9.012)". To be sure the string contains
 * the full representation of the vector, pass a string of size
 * VEC_TO_STRING_LEN. */
extern void Vector_to_string(Vector_t v, char *s, size_t max_len);

/* Returns a new vector which is the result of the addition of 2 vectors */
extern Vector_t Vector_add(Vector_t a, Vector_t b);

/* Returns a new vector which is the unary minus of the given vector.
 * The unary minus is equivalent to multiplying the vector by (-1, -1, -1). */
extern Vector_t Vector_neg(Vector_t v);

/* Returns a new vector representing the result of the scalar
 * multiplication a * v. */
extern Vector_t Vector_scale(Vector_t v, double c);

/* Returns the norm of a 3d vector. ||v|| = sqrt(x^2 + y^2 + z^2) */
extern double Vector_norm(Vector_t v);

/* Returns the dot product of 2 vectors */
extern double Vector_dot(Vector_t a, Vector_t b);

/* Returns a new vector representing the result of 
 * the cross product of two 3d vectors */
extern Vector_t Vector_cross(Vector_t a, Vector_t b);

#endif
