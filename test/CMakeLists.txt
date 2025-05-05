cmake_minimum_required(VERSION 3.27)
find_package(CppUTest REQUIRED)

add_executable(FactTests tests.cpp)

target_include_directories(FactTests PRIVATE ${CppUTest_INCLUDE_DIRS})
target_link_libraries(FactTests PRIVATE Fact CppUTest)

add_test(NAME FactTests COMMAND FactTests)
