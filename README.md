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
Fork this repository. You will work on your own fork.
Clone your fork on your development machine.
Notice the excercise might change, so it is recommended to allow [mirroring](https://about.gitlab.com/blog/2016/12/01/how-to-keep-your-fork-up-to-date-with-its-origin/).

### Create a new branch
In your local repo, create a new branch on top of master:

```sh
git checkout master
git pull
git checkout -b solution/<your name>
```

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

## How to submit your work
1. Create a topic branch `solution/<your name>`
2. Follow the insctructions below about the tasks required at each stage.
3. Once you finished the first stage, submit a Merge Request for
your branch. Prefix your MR title with `WIP:`. This will allow the
tutors to perform CR on your code.
4. As you move through the stages, more jobs in the CI pipeline will
become green, until you complete the exercise.

**Notice:** You SHOULD NOT change the code or the `.gitlab-ci.yml`
or the source files.
All you have to do is create the necessary CMake files that will cause the CI to work.


## Exercise Stages
### Stage 0: Recommended reading
Since the CMake documentation might be too obscure for novel CMakers as yourself, 
I recommend reading [Its time to do CMake right](https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/). 
This will get you through Stages 1-3, solving them using the modern features of CMake.
If you're up to more reading, take a look at [Jason Turner's cpp_starter_project](https://github.com/lefticus/cpp_starter_project).

### Stage 1: basic project
In the first stage all you have to do is create the simplest valid
CMakeLists.txt file that defines a project. It doesn't matter what the project
name is.

### Stage 2: Build the library
In this stage you will write the necessary CMake files to actually compile the
library.

1. Create a target called `Fact`. It should be a library of course.
2. The target is composed of a single source file, `src/fact.cpp`
3. Make sure that the target has the proper include directory (Notice that
`fact.cpp` includes `fact/fact.hpp`)
4. Make sure your target is linked against `spdlog` which is a
**build dependency** of `Fact`. `spdlog` is installed in your conda environment
already. All you have to do is *find* it in your CMake file, and set it as a
dependency of `Fact`.

### Stage 3: Unit tests
There are some unit tests written in `test/tests.cpp`. These tests
are using the `CppUTest` test framework.

1. Create an project-level option for compiling the unit-tests. It
should be `ON` by default.
2. Add an executable target for `tests.cpp`. The target must be
called `FactTests`.
3. Add `CppUTest` as a **build dependency** for `FactTests` (as you
already know - you have to *find* it).

### Stage 4: Installation
This is by far the hardest part. In this stage you will write installation rules that will:
1. Install your library - put the compiled `.a`/`.so` and the public header in the proper location.
2. **Export** your target so that other developers will be able to find your library including all of its dependency after installation.
    1. CMake uses find_package(), in order to find your package you have to create a CMakeConfig.make file (hint: should be names FactConfig.cmake). 
    2. Together with the recommended reading you may use the example found in the last paragraph in the CMake [doc](https://cmake.org/cmake/help/latest/module/CMakePackageConfigHelpers.html).
3. Notice The CMakeLists.txt file in the downstream folder, it uses a certain Namespace for your targert, you should be using the same Namespace. As for cpp programmaing, target namespaces allow multiple developers create targets with the same name (E.G. Steam::Fact, Async::Fact).




## Good Luck!