cmake_minimum_required(VERSION 3.2)

project(containers_tests_project)

# Build googletest
# add_subdirectory(
#     "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
# )

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(
    containers_tests
    test/s_container_tests.cpp
    test/l_container_tests.cpp
)

target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
    containers_tests PRIVATE
    gtest gtest_main
)

set_target_properties(
    containers_tests 
PROPERTIES 
    CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON
)
