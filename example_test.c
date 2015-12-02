/**
 * example usage of winzling unit test framework.
 *
 * Copyright (c) 2015 Johannes Vogel, 84n4n4j03[at]gmail.com
 *
 * MIT License (MIT)
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lib/winzling.h"

void wzl_setup(){
    printf("wzl_setup\n");
}

void wzl_teardown(){
    printf("wzl_teardown\n");
}

static void test_firstTest() {
    printf("test_firstTest\n");
    wzl_EQUAL(1, 1);
    wzl_TRUE(false);
    wzl_STR_EQUAL("one", "one");
    uint32_t one[] = {1,2,3};
    uint32_t two[] = {1,2,3};
    wzl_MEM_EQUAL(one, two, sizeof(one));
}
static void test_secondTest() {
    printf("test_secondTest\n");
    wzl_EQUAL(1, 4);
    wzl_TRUE(true);
    wzl_STR_EQUAL("one", "two");
    uint32_t one[] = {1,2,3};
    uint32_t two[] = {1,2,4};
    wzl_MEM_EQUAL(one, two, sizeof(one));
}

wzl_test tests[] = {
    test_firstTest,
    test_secondTest
};

int main() {
    return wzl_RUN(tests);
}
