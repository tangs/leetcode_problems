#cmake_minimum_required(VERSION 3.10)
#project(dp_solution_pipeline)
#
#set(CMAKE_CXX_STANDARD 17)
#
#set(PROBLEM_NAME 3303)
#
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)
#
#set(SRC_ROOT_PATH ${ROOT_PATH}/src)
#set(SRC_PATH ${SRC_ROOT_PATH}/${PROBLEM_NAME})
#set(TESTS_PATH ${ROOT_PATH}/tests/${PROBLEM_NAME})
#
#include_directories(
#        ${SRC_ROOT_PATH}
#        ${SRC_PATH}
#        ${TESTS_PATH}
#)
#
## test.
#enable_testing()
#
#add_executable(
#        test_${PROBLEM_NAME}
#        ${TESTS_PATH}/test.cc
#)
#target_link_libraries(test_${PROBLEM_NAME} GTest::gtest_main)
#
#
#include(GoogleTest)
#gtest_discover_tests(test_${PROBLEM_NAME})
