#include <stdbool.h>
#include "color.h"
#include "test.h"

static bool test__compare_color__same_color()
{
    Color c1 = get_color(MAROON);
    Color c2 = get_color(MAROON);
    if (compare_color(c1, c2) == 0)
        return true;
    return false;
}

static bool test__compare_color__c1_greater_than_c2()
{
    Color c1 = get_color(SILVER);
    Color c2 = get_color(GRAY);
    if (compare_color(c1, c2) > 0)
        return true;
    return false;
}

static bool test__compare_color__c1_smaller_than_c2()
{
    Color c1 = get_color(BLUE);
    Color c2 = get_color(RED);
    if (compare_color(c1, c2) < 0)
        return true;
    return false;
}

static bool test__get_color__hex_input()
{
    Color expected = rgb(66, 134, 244);
    Color result = get_color(0x4286F4);
    if (compare_color(result, expected) == 0)
        return true;
    return false;
}

static bool test__get_color__color_name_input()
{
    Color expected = rgb(255, 0, 255);
    Color result = get_color(FUCHSIA);
    if (compare_color(result, expected) == 0)
        return true;
    return false;
}

void color_test()
{
    run_test(test__compare_color__c1_greater_than_c2, "compare_color c1 > c2");
    run_test(test__compare_color__c1_smaller_than_c2, "compare_color c1 < c2");
    run_test(test__compare_color__same_color, "compare_color same color");
    run_test(test__get_color__hex_input, "get_color hex input");
    run_test(test__get_color__color_name_input, "get_color color name input");
}
