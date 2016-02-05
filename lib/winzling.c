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

#include "winzling.h"
#include <stdio.h>
#include <stdint.h>

static uint32_t numErrors = 0;

static void printReport(uint32_t numTests) {
    printf("==========================\n");
    printf("number of tests:        %d\n", numTests);
    printf("number of errors:       %d\n", numErrors);
}

uint32_t wzl_run(wzl_test* tests, uint32_t numTests) {
    uint32_t i;
    for(i=0; i<numTests; ++i) {
        uint32_t currentErrors = numErrors;
        printf("\n+++ run test number: %d +++\n", i);
        wzl_setup();
        tests[i]();
        wzl_teardown();
        printf("+++ errors: %d +++\n", numErrors-currentErrors);
    }
    printReport(numTests);
    return numErrors;
}

bool wzl_isTrue(bool condition, char* file, uint32_t line){
    if(!condition){
        ++numErrors;
        fprintf(stderr, "--> error in file: %s, line: %d\n", file, line);
    }
}
