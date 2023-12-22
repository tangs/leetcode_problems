cmake_minimum_required(VERSION 3.10)
project(dp_solution_pipeline)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC_PATH ${ROOT_PATH}/src/70)
set(TESTS_PATH ${ROOT_PATH}/tests/70)

include_directories(
        ${SRC_PATH}
        ${TESTS_PATH}
)

# test.
enable_testing()

add_executable(
        test_70
        ${TESTS_PATH}/test.cc
)
target_link_libraries(test_70 GTest::gtest_main)


include(GoogleTest)
gtest_discover_tests(test_70)
