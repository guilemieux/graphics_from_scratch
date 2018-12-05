#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../src/vector.h"

bool test_Vector_norm()
{
    Vector_t v;
    double norm, expected_norm;
    bool test_failed = false;

    // Test standard vector
    v = Vector_new(1.0, 2.0, 2.0);
    expected_norm = 3.0;
    norm = Vector_norm(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector_free(v);

    // Test negative vector
    v = Vector_new(-2.0, -11.0, 10.0);
    expected_norm = 15.0;
    norm = Vector_norm(v);
    Vector_free(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }

    // Test 0 vector
    v = Vector_new(0.0, 0.0, 0.0);
    expected_norm = 0.0;
    norm = Vector_norm(v);
    Vector_free(v);
    if (norm != expected_norm) {
        printf("FAILED: Vector_norm: expected %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }

    if (!test_failed) {
        printf("Passed: Vector_norm\n");
        return true;
    }
    return false;
}

bool test_Vector_dot_product()
{
    Vector_t u, v;
    double dot_product, expected_dot_product;
    bool test_failed = false;

    u = Vector_new(1.0, 3.0, -5.0);
    v = Vector_new(4.0, -2.0, -1.0);
    expected_dot_product = 3.0;
    dot_product = Vector_dot_product(u, v);
    if (dot_product != expected_dot_product) {
        printf("FAILED: Vector_dot_product: expected %f, got %f\n",
                expected_dot_product, dot_product);
        test_failed = true;
    }
    Vector_free(u);
    Vector_free(v);

    if (!test_failed) {
        printf("Passed: Vector_dot_product\n");
        return true;
    }
    return false;
}

bool test_Vector_to_string()
{
    char expected_str_rep[VEC_TO_STRING_LEN];
    char str_rep[VEC_TO_STRING_LEN];
    Vector_t v;
    bool test_failed = false;

    // Padding zeros
    v = Vector_new(-1.0, 1.0, 2.01);
    sprintf(expected_str_rep, "(-1.000, 1.000, 2.010)");
    Vector_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    // Rounding
    v = Vector_new(0.9999, 0.0, 0.0);
    sprintf(expected_str_rep, "(1.000, 0.000, 0.000)");
    Vector_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    // Rounding with 5
    v = Vector_new(0.0005, -0.0005, 0.0);
    sprintf(expected_str_rep, "(0.001, -0.001, 0.000)");
    Vector_to_string(v, str_rep, VEC_TO_STRING_LEN);
    Vector_free(v);
    if (strcmp(str_rep, expected_str_rep) != 0) {
        printf("FAILED: Vector_to_string: expected %s, got %s\n",
                expected_str_rep, str_rep);
        test_failed = true;
    }

    if (!test_failed) {
        printf("Passed: Vector_to_string\n");
        return true;
    }
    return false;
}

int main(void)
{
    bool norm_test = test_Vector_norm();
    bool dot_test = test_Vector_dot_product();
    bool tostring_test = test_Vector_to_string();

    if (norm_test && dot_test && tostring_test) {
        printf("All vector tests passed!\n");
    }

    return 0;
}
