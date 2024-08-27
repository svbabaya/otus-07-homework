cmake_minimum_required(VERSION 3.2)

project(containers_tests)

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
)

# Test target
add_executable(
    test_assertions
    test/test_assertions.cpp
)

set_target_properties(test_assertions PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)