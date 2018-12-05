#include <stdio.h>
#include <stdbool.h>
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

int main(void)
{
    bool norm2d_test = test_Vector2d_norm();
    bool norm3d_test = test_Vector3d_norm();
    bool dot2d_test = test_Vector2d_dot_product();
    bool dot3d_test = test_Vector3d_dot_product();
    if (norm2d_test && norm3d_test
            && dot2d_test && dot3d_test) {
        printf("All vector tests passed!\n");
    }
    return 0;
}
