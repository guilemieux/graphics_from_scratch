#include <stdio.h>
#include <stdbool.h>
#include "../includes/color.h"

bool test__compare_color__same_color()
{
    struct color c1 = get_color(MAROON);
    struct color c2 = get_color(MAROON);
    if (compare_color(c1, c2) == 0) return true;
    return false;
}

bool test__compare_color__c1_greater_than_c2()
{
    struct color c1 = get_color(SILVER);
    struct color c2 = get_color(GRAY);
    if (compare_color(c1, c2) > 0) return true;
    return false;
}

bool test__compare_color__c1_smaller_than_c2()
{
    struct color c1 = get_color(BLUE);
    struct color c2 = get_color(RED);
    if (compare_color(c1, c2) < 0) return true;
    return false;
}

bool test__get_color__hex_input()
{
    struct color expected = rgb(66, 134, 244);
    struct color result = get_color(0x4286F4);
    if (compare_color(result, expected) == 0) return true;
    return false;
}

bool test__get_color__color_name_input()
{
    struct color expected = rgb(255, 0, 255);
    struct color result = get_color(FUCHSIA);
    if (compare_color(result, expected) == 0) return true;
    return false;
}

void run_test(bool (*test)(), const char *test_name)
{
    if (test())
        printf("PASSED: %s\n", test_name);
    else
        printf("FAILED: %s\n", test_name);
} 

int main()
{
    run_test(test__compare_color__c1_greater_than_c2, "compare_color c1 > c2");
    run_test(test__compare_color__c1_smaller_than_c2, "compare_color c1 < c2");
    run_test(test__compare_color__same_color, "compare_color same color");
    run_test(test__get_color__hex_input, "get_color hex input");
    run_test(test__get_color__color_name_input, "get_color color name input");
    return 0;
}
