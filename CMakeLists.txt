cmake_minimum_required(VERSION 4.2)
project(frequencyTable)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(frequencyTable main.cpp utils/bubbleSort.cpp)
