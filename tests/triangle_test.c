#include <stdio.h>
#include <stdbool.h>
#include "../src/triangle.h"
#include "../src/vector.h"

bool test_area()
{   
    Vector_t a = Vector_new(0.0, 0.0, 0.0);
    Vector_t b = Vector_new(0.0, 1.0, 0.0);
    Vector_t c = Vector_new(0.0, 0.0, 1.0);
    Triangle_t t = Triangle_new(a, b, c);
    double expected = 0.5;
    double area = Triangle_area(t);
    if (area != expected) {
        printf("FAILED: Triangle_area: expected %f, got %f\n",
                expected, area);
        return false;
    }
    return true;
}

int main()
{
    bool area_test = test_area();
    if (area_test) {
        printf("All tests passed\n");
    }
    return 0;
}
