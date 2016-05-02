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
    // printf("setup\n");
}

void teardown(){
    // printf("teardown\n");
}

static void firstTest() {
    // printf("firstTest\n");
    wzl_EQUAL(1, 1);
    wzl_TRUE(false);
    wzl_STR_EQUAL("one", "one");
    uint32_t one[] = {1,2,3};
    uint32_t two[] = {1,2,3};
    wzl_MEM_EQUAL(one, two, sizeof(one));
}
static void secondTest() {
    // printf("secondTest\n");
    wzl_EQUAL(1, 4);
    wzl_TRUE(true);
    wzl_STR_EQUAL("one", "two");
    uint32_t one[] = {1,2,3};
    uint32_t two[] = {1,2,4};
    if(! wzl_MEM_EQUAL(one, two, sizeof(one))) {
        wzl_PRINT_NUM_ARRAY(one, 3);
        wzl_printMemory(one, sizeof(one));
    }
}

wzl_function tests[] = {
    firstTest,
    secondTest
};

int main() {
    uint32_t numErrors = wzl_RUN("test_group_1", setup, teardown, tests);
    numErrors += wzl_RUN("test_group_2", setup, teardown, tests);
    return numErrors;
}
