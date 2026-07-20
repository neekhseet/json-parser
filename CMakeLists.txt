cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_library(proj_lib STATIC
    sources/json.c
)
target_include_directories(proj_lib PUBLIC headers)

add_executable(proj_tests
    tests/test_proj.cpp
)

target_link_libraries(proj_tests PRIVATE proj_lib gtest gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(proj_tests)
