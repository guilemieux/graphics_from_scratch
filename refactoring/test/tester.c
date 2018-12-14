#include <stdio.h>
#include "test.h"

void print_nl()
{
    printf("\n");
}

int main()
{
    print_nl();
    color_test();
    print_nl();
    linalg_test();
    print_nl();
    return 0;
}
