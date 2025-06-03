cmake_minimum_required(VERSION 3.27)

# CppUTest conda package until version 3.8 have
# installed all the Cmake-related files (such as CppUTestConfig.cmake)
# in /lib of the conda environment, however version 4.0 have
# installed those files into /lib64 of the conda environment which
# have failed the "vanilla" find_package, by adding the hints
# find_package is able to find CppUTest in both places without
# any issue whatsoever.
find_package(CppUTest REQUIRED HINTS /lib /lib64)

add_executable(FactTests tests.cpp)

target_include_directories(FactTests PRIVATE ${CppUTest_INCLUDE_DIRS})
target_link_libraries(FactTests PRIVATE Fact CppUTest)

add_test(NAME FactTests COMMAND FactTests)
