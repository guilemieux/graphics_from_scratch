#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../src/vector.h"

bool test_Vector2d_norm()
{   
    Vector2d_t v;
    double norm, expected_norm;
    bool test_failed = false;
    
    // Test standard vector
    v = Vector2d_new(3.0, 4.0);
    expected_norm = 5.0;
    norm = Vector2d_norm(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector2d_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector2d_free(v);

    // Test negative vector
    v = Vector2d_new(-12.0, -5.0);
    expected_norm = 13.0;
    norm = Vector2d_norm(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector2d_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector2d_free(v);

    // Test 0 vector
    v = Vector2d_new(0.0, 0.0);
    expected_norm = 0.0;
    norm = Vector2d_norm(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector2d_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector2d_free(v);

    if (!test_failed) {
        printf("Passed: Vector2d_norm\n");
        return true;
    }
    return false;
}

bool test_Vector3d_norm()
{
    Vector3d_t v;
    double norm, expected_norm;
    bool test_failed = false;

    // Test standard vector
    v = Vector3d_new(1.0, 2.0, 2.0);
    expected_norm = 3.0;
    norm = Vector3d_norm(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector3d_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector3d_free(v);

    // Test negative vector
    v = Vector3d_new(-2.0, -11.0, 10.0);
    expected_norm = 15.0;
    norm = Vector3d_norm(v);
    Vector3d_free(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector3d_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }

    // Test 0 vector
    v = Vector3d_new(0.0, 0.0, 0.0);
    expected_norm = 0.0;
    norm = Vector3d_norm(v);
    Vector3d_free(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector3d_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }

    if (!test_failed) {
        printf("Passed: Vector3d_norm\n");
        return true;
    }
    return false;
}

bool test_Vector2d_dot_product()
{
    Vector2d_t u, v;
    double dot_product, expected_dot_product;
    bool test_failed = false;

    u = Vector2d_new(-4.0, -9.0);
    v = Vector2d_new(-1.0, 2.0);
    expected_dot_product = -14.0;
    dot_product = Vector2d_dot_product(u, v);
    Vector2d_free(u);
    Vector2d_free(v);
    if (dot_product != expected_dot_product) {
        printf("FAILED: Vector2d_dot_product: expected %f, got %f\n",
                expected_dot_product, dot_product);
        test_failed = true;
    }

    if (!test_failed) {
        printf("Passed: Vector2d_dot_product\n");
        return true;
    }
    return false;
}

bool test_Vector3d_dot_product()
{
    Vector3d_t u, v;
    double dot_product, expected_dot_product;
    bool test_failed = false;

    u = Vector3d_new(1.0, 3.0, -5.0);
    v = Vector3d_new(4.0, -2.0, -1.0);
    expected_dot_product = 3.0;
    dot_product = Vector3d_dot_product(u, v);
    if (dot_product != expected_dot_product) {
        printf("FAILED: Vector3d_dot_product: expected %f, got %f\n",
                expected_dot_product, dot_product);
        test_failed = true;
    }
    Vector3d_free(u);
    Vector3d_free(v);

    if (!test_failed) {
        printf("Passed: Vector3d_dot_product\n");
        return true;
    }
    return false;
}

bool test_Vector2d_to_string()
{
    char expected_str_rep[VEC_TO_STRING_LEN];
    char str_rep[VEC_TO_STRING_LEN];
    Vector2d_t v;
    bool test_failed = false;

    // Padding zeros
    v = Vector2d_new(-1000.12, 10000000.1);
    sprintf(expected_str_rep, "(-1000.120, 10000000.100)");
    Vector2d_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector2d_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector2d_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    // Rounding
    v = Vector2d_new(0.9999, 0.0);
    sprintf(expected_str_rep, "(1.000, 0.000)");
    Vector2d_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector2d_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector2d_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    // Rounding with 5
    v = Vector2d_new(0.0005, -0.0005);
    sprintf(expected_str_rep, "(0.001, -0.001)");
    Vector2d_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector2d_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector2d_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    if (!test_failed) {
        printf("Passed: Vector2d_to_string\n");
        return true;
    }
    return false;
}

bool test_Vector3d_to_string()
{
    char expected_str_rep[VEC_TO_STRING_LEN];
    char str_rep[VEC_TO_STRING_LEN];
    Vector3d_t v;
    bool test_failed = false;

    // Padding zeros
    v = Vector3d_new(-1.0, 1.0, 2.01);
    sprintf(expected_str_rep, "(-1.000, 1.000, 2.010)");
    Vector3d_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector3d_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector3d_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    // Rounding
    v = Vector3d_new(0.9999, 0.0, 0.0);
    sprintf(expected_str_rep, "(1.000, 0.000, 0.000)");
    Vector3d_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector3d_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector3d_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    // Rounding with 5
    v = Vector3d_new(0.0005, -0.0005, 0.0);
    sprintf(expected_str_rep, "(0.001, -0.001, 0.000)");
    Vector3d_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector3d_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector3d_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    if (!test_failed) {
        printf("Passed: Vector3d_to_string\n");
        return true;
    }
    return false;
}

int main(void)
{
    bool norm2d_test = test_Vector2d_norm();
    bool norm3d_test = test_Vector3d_norm();
    bool dot2d_test = test_Vector2d_dot_product();
    bool dot3d_test = test_Vector3d_dot_product();
    bool tostring2d_test = test_Vector2d_to_string();
    bool tostring3d_test = test_Vector3d_to_string();

    if (norm2d_test && norm3d_test
            && dot2d_test && dot3d_test
            && tostring2d_test && tostring3d_test) {
        printf("All vector tests passed!\n");
    }

    return 0;
}
