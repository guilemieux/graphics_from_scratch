#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "test.h"
#include "linalg.h"

static bool test__vec_equal__equal_vec()
{
    Vector a = VECTOR(1, 1, 1);
    Vector b = VECTOR(1.0, 1.0, 1.0);
    bool expected = true;
    bool result = vec_equal(a, b);
    return expected == result;
}

static bool test__vec_equal__diff_vec()
{
    Vector a = VECTOR(1, 1, 1);
    Vector b = VECTOR(1, 1, 1.01);
    bool expected = false;
    bool result = vec_equal(a, b);
    return expected == result;
}

static bool test__add_vec()
{
    Vector a = VECTOR(1, 1, 1);
    Vector b = VECTOR(-1, -1, -1);
    Vector expected = VECTOR(0, 0, 0);
    Vector result = add_vec(a, b);
    return vec_equal(result, expected);
}

static bool test__dot_product()
{
    Vector a = VECTOR(1, 3, -5);
    Vector b = VECTOR(4, -2, -1);
    double expected = 3;
    double result = dot_product(a, b);
    return expected == result;
}

static bool test__det()
{
    Matrix m;
    m[0][0] = 6;
    m[0][1] = 1;
    m[0][2] = 1;
    m[1][0] = 4;
    m[1][1] = -2;
    m[1][2] = 5;
    m[2][0] = 2;
    m[2][1] = 8;
    m[2][2] = 7;
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
