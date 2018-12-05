#include <stdio.h>
#include "../src/vector.h"

int main(void)
{
    Vector2d_t v = Vector2d_new(0.0, 0.0);
    Vector2d_print(v);
    Vector2d_free(v);
}
