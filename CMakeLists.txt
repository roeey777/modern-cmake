cmake_minimum_required(VERSION 3.27)
project(
  libfactorial
  VERSION 0.0.1
  LANGUAGES CXX)

add_subdirectory(src)

target_include_directories(
  Fact
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_options(Fact PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_features(Fact PRIVATE cxx_std_11)

find_package(spdlog 1.12.0 REQUIRED)

# spdlog is used internally by Fact and therefor shouldn't be propagated into
# other targets.
target_link_libraries(Fact PRIVATE spdlog::spdlog)
