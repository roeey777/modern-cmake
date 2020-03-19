# CMake Training
This repository will help you learn **Modern CMake**

## Exercise Goals

By the time you complete this exercise you will know:
1. Basic CMake - defining a project for a simple library
2. How to enable unit-tests in CMake
3. How to enable static code analisys using `cppcheck` and `clang-tidy`
4. How to export your library in a modern way so that other developers will be
able to import it as a CMake dependency.

## The Exercise
This repo contains a simple C++ library: `Fact`
The `Fact` library has only one function:

```c++
unsigned in factorial(unsigned int);
```

which computes the factorial of a certain number.
There are some unit-tests and even a downstream dependency test.

There is also a CI pipeline set-up for building the library and running the tests!

However, this repo does not have any build-system support, so all this goodies cannot be put to use, and the pipeline fails miserably.

**Your mission** - should you choose to accept it - is to make the CI pipeline work by writing the necessary CMake files that will define how the library is built and installed.
