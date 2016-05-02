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
 * The fp type for a setup, teardown and test functions
 */
typedef void (*wzl_function)();


// ----------------Compare Macros----------------

/**
 * Run tests. Simply set up an array of wzl_test functions and pass it along.
 */
#define wzl_RUN(name, setup, teardown, tests) wzl_run(name, setup, teardown, tests, sizeof(tests)/sizeof(tests[0]))


/**
 * Compare two variables, pointers, values, etc.
 */
#define wzl_EQUAL(a, b) ((wzl_isTrue(a==b, __FILE__, __LINE__))?:fprintf(stderr, "\texpected:\t%d (0x%x)\n\tbut was:\t%d (0x%x)\n", a, a, b, b))

/**
 * Check if passed condition is true.
 */
#define wzl_TRUE(a) ((wzl_isTrue(a, __FILE__, __LINE__))?:fprintf(stderr, "\texpected: true, but was: false\n"))

/**
 * Compare two strings.
 */
#define wzl_STR_EQUAL(a, b) ((wzl_isTrue(0==strcmp(a, b), __FILE__, __LINE__))?:fprintf(stderr, "\texpected:\t%s	\n\tbut was:\t%s\n", a, b))

/**
 * Compare two memory regions. Use for arrays, structs, etc.
 */
#define wzl_MEM_EQUAL(a, b, numBytes) (wzl_isTrue(0==memcmp(a, b, numBytes), __FILE__, __LINE__))

// ----------------helper----------------
/**
 * Print all elements of an array of numbers.
 */
#define wzl_PRINT_NUM_ARRAY(array, numElements) for(uint32_t i=0; i<numElements; ++i) { printf("%d ", array[i]); }; printf("\n");

/**
 * Print all bytes of a memory region.
 */
void wzl_printMemory(void* mem, uint32_t numBytes);

// ----------------Internally used----------------
/**
 * Usually not called directly. Instead use macro api.
 */
uint32_t wzl_run(char* name, wzl_function setup, wzl_function teardown, wzl_function* tests, uint32_t numTests);

/**
 * Usually not called directly. Instead use macro api.
 */
bool wzl_isTrue(bool condition, char* file, uint32_t line);


#endif //WINZLING_H_
