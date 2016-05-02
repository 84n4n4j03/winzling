/**
 * example usage of winzling unit test framework.
 *
 * Copyright (c) 2015 Johannes Vogel, 84n4n4j03[at]gmail.com
 *
 * MIT License (MIT)
 *
 * visit: https://github.com/84n4n4j03/winzling
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lib/winzling.h"

void setup(){
}

void teardown(){;
}

static void firstTest() {
    wzl_EQUAL(1, 1);
}


wzl_function tests[] = {
    firstTest,
};

int main() {
    return wzl_RUN("my_test", setup, teardown, tests);
}
