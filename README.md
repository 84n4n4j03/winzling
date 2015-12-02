# winzling
a tiny C/C++ unit test framework

## Installation
Easy - winzling consists of two files. Include "winzling.h",
compile "winzling.c" and link against it. That's it.
No further dependencies, only standard lib.

## Usage
"example_test" contains everything available.
Currently the idea is to build one executable per test.
This is straightworward when developing in one test.
Use linker substitution for isolation and mocking to reduce the amount of
files to build. Of course f2fp works as well.

To execute all available tests
write a simple script that looks for Makefiles recursively and execute each test
rule. Accumulate the returned error level to count the total errors.

Another option is to hook them to a root Makefile that builds all c-files and
links each test.


