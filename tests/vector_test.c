#include <stdio.h>
#include <stdbool.h>
#include "../src/vector.h"

bool test_Vector2d_norm()
{   
    Vector2d_t v;
    double norm;
    double expected_norm;
    bool test_failed = false;
    
    // Test standard vector
    v = Vector2d_new(3.0, 4.0);
    expected_norm = 5.0;
    norm = Vector2d_norm(v);
    if (norm != expected_norm) {
        printf("Vector2d_norm test failed: expected norm of %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector2d_free(v);

    // Test negative vector
    v = Vector2d_new(-12.0, -5.0);
    expected_norm = 13.0;
    norm = Vector2d_norm(v);
    if (norm != expected_norm) {
        printf("Vector2d_norm test failed: expected norm of %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector2d_free(v);

    // Test 0 vector
    v = Vector2d_new(0.0, 0.0);
    expected_norm = 0.0;
    norm = Vector2d_norm(v);
    if (norm != expected_norm) {
        printf("Vector2d_norm test failed: expected norm of %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector2d_free(v);

    if (!test_failed) {
        printf("Vector2d_norm test passed\n");
        return true;
    }
    return false;
}

bool test_Vector3d_norm()
{
    Vector3d_t v;
    double norm;
    double expected_norm;
    bool test_failed;

    // Test standard vector
    v = Vector3d_new(1.0, 2.0, 2.0);
    expected_norm = 3.0;
    norm = Vector3d_norm(v);
    if (norm != expected_norm) {
        printf("Vector3d_norm test failed: expected norm of %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector3d_free(v);

    // Test negative vector
    v = Vector3d_new(-2.0, -11.0, 10.0);
    expected_norm = 15.0;
    norm = Vector3d_norm(v);
    if (norm != expected_norm) {
        printf("Vector3d_norm test failed: expected norm of %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector3d_free(v);

    // Test 0 vector
    v = Vector3d_new(0.0, 0.0, 0.0);
    expected_norm = 0.0;
    norm = Vector3d_norm(v);
    if (norm != expected_norm) {
        printf("Vector3d_norm test failed: expected norm of %f, got %f\n",
                expected_norm, norm);
        test_failed = true;
    }
    Vector3d_free(v);

    if (!test_failed) {
        printf("Vector3d_norm test passed\n");
        return true;
    }
    return false;
}

int main(void)
{
    if (test_Vector2d_norm() && test_Vector3d_norm()) {
        printf("All tests passed!\n");
    }
    return 0;
}
