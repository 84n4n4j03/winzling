/**
 * winzling - a tiny C/C++ unit test framework
 *
 * Copyright (c) 2015 Johannes Vogel, 84n4n4j03[at]gmail.com
 *
 * MIT License (MIT)
 *
 * visit: https://github.com/84n4n4j03/winzling
 *
 */

#ifndef WINZLING_H_
#define WINZLING_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/**
 * The fp type for a test function
 */
typedef void (*wzl_test)();


void wzl_setup();
void wzl_teardown();

/**
 * Run tests. Simply set up an array of wzl_test functions and pass it along.
 */
#define wzl_RUN(tests) wzl_run(tests, sizeof(tests)/sizeof(tests[0]))

/**
 * Compare two variables, pointers, values, etc.
 */
#define wzl_EQUAL(a, b) (wzl_isTrue(a==b, __FILE__, __LINE__))

/**
 * Check if passed condition is true.
 */
#define wzl_TRUE(a) (wzl_isTrue(a, __FILE__, __LINE__))

/**
 * Compare two strings.
 */
#define wzl_STR_EQUAL(a, b) (wzl_isTrue(0==strcmp(a, b), __FILE__, __LINE__))

/**
 * Compare two memory regions. Use for arrays, structs, etc.
 */
#define wzl_MEM_EQUAL(a, b, numBytes) (wzl_isTrue(0==memcmp(a, b, numBytes), __FILE__, __LINE__))

/**
 * Usually not called directly. Instead use macro api.
 */
uint32_t wzl_run(wzl_test* tests, uint32_t numTests);

/**
 * Usually not called directly. Instead use macro api.
 */
bool wzl_isTrue(bool condition, char* file, uint32_t line);





#endif //WINZLING_H_
