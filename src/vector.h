/*
 * vector.h
 * Guillaume Lemieux
 */
#ifndef _VECTOR_H_
#define _VECTOR_H_

#define T Vector_t

/* Recomended size of the buffer for the to_string methods */
#define VEC_TO_STRING_LEN 64

typedef struct T *T;

/* Creation and destruction of 3d vectors */
extern T Vector_new(double x, double y, double z);
extern void Vector_free(T v);


/* Puts a representation of a 3d vector in a string. The format of the 
 * output string is "(-1.234, 5.678, -9.012)". To be sure the string contains
 * the full representation of the vector, pass a string of size
 * VEC_TO_STRING_LEN. */
extern void Vector_to_string(T v, char *s, size_t max_len);

/* Returns a new vector which is the result of the addition of 2 vectors */
extern T Vector_add(T u, T v);

/* Returns a new vector which is the unary minus of the given vector.
 * The unary minus is equivalent to multiplying the vector by (-1, -1, -1). */
extern T Vector_minus(T v);

/* Returns a new vector representing the result of the scalar
 * multiplication a * v. */
extern T Vector_scale(T v, double a);

/* Returns the norm of a 3d vector. ||v|| = sqrt(x^2 + y^2 + z^2) */
extern double Vector_norm(T v);

/* Returns the dot product of 2 vectors */
extern double Vector_dot(T a, T b);

/* Returns a new vector representing the result of 
 * the cross product of two 3d vectors */
extern T Vector_cross(T a, T b);

#undef T

#endif
