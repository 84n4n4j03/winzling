# winzling
a tiny C/C++ unit test framework

## Installation
Easy - winzling consists of two files. Include "winzling.h",
compile "winzling.c" and link against it. That's it.
No further dependencies, only standard lib.
Of course you can also add it as git submodule to you project.

## Usage
"example_test" contains everything available. Find some sections below
explaining the most important things.
The easiest way is to build one executable per test.
This is straightworward when developing in one test.
Use linker substitution for isolation and mocking to reduce the amount of
files to build. Of course f2fp works as well.

To execute all available tests
write a simple script that looks for Makefiles recursively and execute each test
rule. Accumulate the returned error level to count the total errors.

Another option is to hook them to a root Makefile that builds all c-files and
links each test.

Also you can write a little bit of code and simply group them as testuites.


## Check Macros
```cpp
wzl_EQUAL(a, b);               //Compare two variables, pointers, values, etc.
wzl_TRUE(a);                   //Check if passed condition is true.
wzl_STR_EQUAL(a, b);           //Compare two strings.
wzl_MEM_EQUAL(a, b, numBytes); //Compare two memory regions.
                               //            -> Use for arrays, structs, etc.
```
Every winzling symbol is prefixed `wzl_`.

## Basic Usage
Write setup, teardown, and test routines as simple void functions:
```cpp
void setup(){}
void teardown(){}
```
As in most unit test frameworks `setup` is called before and `teardown` after
each test.

Add a function for every test:
```cpp
void test_something() {
    wzl_EQUAL(1, 2);
}
```
You're free to choose any name you like, the only constraint is the signature
with returntype void and no parameter.

Add all test functions to an array of type `wzl_test`:
```cpp
wzl_test tests[] = {
    test_something,
    test_someOtherThing
};
```

Finally use `wzl_RUN` to run the tests by passing the array.
It returns the number of errors. You can forward them as errorlevel to the
calling command line by returning them in your main like so:
```cpp
int main() {
    return wzl_RUN("test_name", setup, teardown, tests);
}
```
That's it.


## extending and modifying
Instead of providing tons of features and options to enable and disable them
simply use code to add what you need. The framework is so simple that everyone
should be able to pimp it.
