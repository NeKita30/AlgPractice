cmake_minimum_required(VERSION 3.22)
project(Practice)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_FLAGS)

add_executable(bin_search Binary_search/BinSearch.cpp)
add_executable(pref_sum Prefix_sum/PrefixSum.cpp)
add_executable(stack Stack/Stack.cpp)
add_executable(queue Queue/Queue.cpp)
add_executable(queue_by_stacks Queue/QueueByTwoStack.cpp)
