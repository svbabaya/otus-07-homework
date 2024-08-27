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

# Add src to the include directories for the test target
target_include_directories(
    test_assertions PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Link test target against gtest libraries
target_link_libraries(
    test_assertions PRIVATE
    gtest gtest_main
)

set_target_properties(
    test_assertions 
PROPERTIES 
    CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON
)