#ifndef _TEST_H_
#define _TEST_H_

#include <stdbool.h>

extern void run_test(bool (*test)(), const char *test_name);

extern void color_test();
extern void linalg_test();

#endif
