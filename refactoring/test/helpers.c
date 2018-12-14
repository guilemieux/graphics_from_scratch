#include <stdbool.h>
#include <stdio.h>
#include "test.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

void run_test(bool (*test)(), const char *test_name)
{
    if (test())
        printf("  %s✔ PASSED:%s %s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET, test_name);
    else
        printf("  %s✘ FAILED:%s %s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET, test_name);
}
