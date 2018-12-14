#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "test.h"
#include "linalg.h"

static bool test__vec_equal__equal_vec()
{
    struct vector a = VECTOR(1, 1, 1);
    struct vector b = VECTOR(1.0, 1.0, 1.0);
    bool expected = true;
    bool result = vec_equal(a, b);
    return expected == result;
}

static bool test__vec_equal__diff_vec()
{
    struct vector a = VECTOR(1, 1, 1);
    struct vector b = VECTOR(1, 1, 1.01);
    bool expected = false;
    bool result = vec_equal(a, b);
    return expected == result;
}

static bool test__add_vec()
{
    struct vector a = VECTOR(1, 1, 1);
    struct vector b = VECTOR(-1, -1, -1);
    struct vector expected = VECTOR(0, 0, 0);
    struct vector result = add_vec(a, b);
    return vec_equal(result, expected);
}

static bool test__dot_product()
{
    struct vector a = VECTOR(1, 3, -5);
    struct vector b = VECTOR(4, -2, -1);
    double expected = 3;
    double result = dot_product(a, b);
    return expected == result;
}

static bool test__det()
{
    struct matrix m;
    m.x[0][0] = 6;
    m.x[0][1] = 1;
    m.x[0][2] = 1;
    m.x[1][0] = 4;
    m.x[1][1] = -2;
    m.x[1][2] = 5;
    m.x[2][0] = 2;
    m.x[2][1] = 8;
    m.x[2][2] = 7;
    double expected = -306;
    double result = det(m);
    return expected == result;
}

void linalg_test()
{
    run_test(test__vec_equal__equal_vec, "vec_equal equal vectors");
    run_test(test__vec_equal__diff_vec, "vec_equal different vectors");
    run_test(test__add_vec, "add_vec");
    run_test(test__dot_product, "dot_product");
    run_test(test__det, "matrix determinant");
}
