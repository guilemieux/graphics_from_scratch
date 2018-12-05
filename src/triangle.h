#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#define T Triangle_t

typedef struct T *T;

extern T Triangle_new(Vector3d_t a, Vector3d_t b, Vector3d_t c);
extern void Triangle_free(T t);
extern double Triangle_area(T t);

#endif
