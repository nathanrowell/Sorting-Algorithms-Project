cmake_minimum_required(VERSION 3.26)
project(SortingMiniProj)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SortingMiniProj
        main.cpp
        Sort.cpp
        Sort.hpp
        testSort.cpp
        testSort.hpp)
