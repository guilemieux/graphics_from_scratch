/*
 * vector.h
 * Guillaume Lemieux
 */
#ifndef VECTOR_H
#define VECTOR_H

/************************************************
 * 2D VECTOR
 ***********************************************/
typedef struct Vector2d_t *Vector2d_t;

/* Creation and destruction of a 2d vectors */
extern Vector2d_t Vector2d_new(double x, double y);
extern void Vector2d_free(Vector2d_t v);

/* Prints the 2d vector to stdout with the format: (x, y) */
extern void Vector2d_print(Vector2d_t v);

/* Returns a new vector which is the result of the addition of 2 vectors */
extern Vector2d_t Vector2d_add(Vector2d_t u, Vector2d_t v);

/* Returns a new vector which is the unary minus of the given vector.
 * The unary minus is equivalent to multiplying the vector by (-1, -1). */
extern Vector2d_t Vector2d_unary_minus(Vector2d_t v);

/* Returns a new vector representing the result of the scalar 
 * multiplication a * v. */
extern Vector2d_t Vector2d_scale(Vector2d_t v, double a);

/* Returns the norm of a 2d vector. ||v|| = sqrt(x^2 + y^2). */
extern double Vector2d_norm(Vector2d_t v);

/* Returns the dot product of 2 vectors */
extern double Vector2d_dot_product(Vector2d_t a, Vector2d_t b);

/************************************************
 * 3D VECTOR
 ***********************************************/
typedef struct Vector3d_t *Vector3d_t;

/* Creation and destruction of 3d vectors */
extern Vector3d_t Vector3d_new(double x, double y, double z);
extern void Vector3d_free(Vector3d_t v);

/* Prints the 3d vector to stdout with the format: (x, y, z) */
extern void Vector3d_print(Vector3d_t v);

/* Returns a new vector which is the result of the addition of 2 vectors */
extern Vector3d_t Vector3d_add(Vector3d_t u, Vector3d_t v);

/* Returns a new vector which is the unary minus of the given vector.
 * The unary minus is equivalent to multiplying the vector by (-1, -1, -1). */
extern Vector3d_t Vector3d_unary_minus(Vector3d_t v);

/* Returns a new vector representing the result of the scalar
 * multiplication a * v. */
extern Vector3d_t Vector3d_scale(Vector3d_t v, double a);

/* Returns the norm of a 3d vector. ||v|| = sqrt(x^2 + y^2 + z^2) */
extern double Vector3d_norm(Vector3d_t v);

/* Returns the dot product of 2 vectors */
extern double Vector3d_dot_product(Vector3d_t a, Vector3d_t b);

#endif