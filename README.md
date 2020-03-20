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
unsigned int factorial(unsigned int);
```

which computes the factorial of a certain number.
There are some unit-tests and even a downstream dependency test.

There is also a CI pipeline set-up for building the library and running the tests!

However, this repo does not have any build-system support, so all this goodies cannot be put to use, and the pipeline fails miserably.

**Your mission** - should you choose to accept it - is to make the CI pipeline work by writing the necessary CMake files that will define how the library is built and installed.

## Getting started
### Create a fork
Fork this repository. you will work against your own fork on a topic branch, and when you'll be ready - submit a Pull Request.

### Installing `conda`
**Use `conda` for this exercise**. It is a great tool for setting up an isolated
development environment with all the dependencies for your project.
I recommend using [miniconda](https://docs.conda.io/en/latest/miniconda.html).

Install `miniconda` and verify that it is working:
```sh
conda -V
```

### Creating development environment
For your convenience, this project contains `environment.yml` file, which
describes the environment necessary for this project. You can create the environment by running the following command:
```sh
conda env create
```

The environment name will be `modern-cmake` and you can activate your environment using:
```sh
conda activate modern-cmake
```
### Reproduce the CI failure
Look at the `.gitlab-ci.yml` file. It contains two jobs:
1. `build` - which builds the library, run static checks and unit-tests.
2. `downstream-test` - which installs the library and try to link a simple
executable against it.

Each job contains a `script` section, which contains the actual steps to perform
the job.

Let's try to run the `build` job commands as they appear in `.gitlab-ci.yml`:
```sh
cmake -S . -B build/upstream -DCMAKE_FIND_ROOT_PATH=$CONDA_PREFIX -DENABLE_CPPCHECK=ON -DENABLE_TESTING=ON
cmake --build build/upstream
cd build/upstream && ctest -V
```

It should fail immediately since you don't have a top-level `CMakeLists.txt` file.

## Get to work
1. Create a topic branch `solution/<your name>`
2. Make the necessary changes so that the CI passes on your branch.
3. When done, submit a Merge Request.

**Notice:** You SHOULD NOT change the code or the `.gitlab-ci.yml`.
All you have to do is create the necessary CMake files that will cause the CI to work.
