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

static void printReport(uint32_t numTests, uint32_t numErrors) {
    printf("==========================\n");
    printf("number of tests:        %d\n", numTests);
    printf("number of errors:       %d\n", numErrors);
}

uint32_t wzl_run(char* name, wzl_function setup, wzl_function teardown, wzl_function* tests, uint32_t numTests) {
    printf("\n\n%s\n---------------------------\n", name);
    numErrors = 0;
    uint32_t i;
    for(i=0; i<numTests; ++i) {
        uint32_t currentErrors = numErrors;
        printf("\n+++ run test number: %d +++\n", i);
        setup();
        tests[i]();
        teardown();
        printf("+++ errors: %d +++\n", numErrors-currentErrors);
    }
    printReport(numTests, numErrors);
    return numErrors;
}

bool wzl_isTrue(bool condition, char* file, uint32_t line){
    if(!condition){
        ++numErrors;
        fprintf(stderr, "--> error in file: %s, line: %d\n", file, line);
    }
    return condition;
}

void wzl_printMemory(void* mem, uint32_t numBytes) {
    uint32_t i = 0;
    for(i=0; i<numBytes; ++i) {
        printf("%02x ", ((uint8_t*)mem)[i]);
    }
    printf("\n");
}

