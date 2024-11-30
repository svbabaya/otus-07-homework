cmake_minimum_required(VERSION 3.2)

project(containers_tests_project)

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
)

# Test target
add_executable(
    containers_tests
    test/s_container_tests.cpp
    test/l_container_tests.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Link test target against gtest libraries
target_link_libraries(
    containers_tests PRIVATE
    gtest gtest_main
)

set_target_properties(
    containers_tests 
PROPERTIES 
    CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON
)
