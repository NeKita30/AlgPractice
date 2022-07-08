cmake_minimum_required(VERSION 3.22)
project(Practice)

set(CMAKE_C_STANDARD 17)

include_directories(Prefix_sum)
include_directories(Binary_search)
include_directories(Stack)
include_directories(Queue)
# include_directories(Merge_sort)
add_executable(exper Merge_sort/MergeSortUnRecursively.cpp)
