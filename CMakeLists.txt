cmake_minimum_required(VERSION 3.27)

project(leetcode_problems)

set(CMAKE_CXX_STANDARD 20)
set(ROOT_PATH ${CMAKE_CURRENT_LIST_DIR})

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
