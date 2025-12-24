cmake_minimum_required(VERSION 4.0)
project(wet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(wet
        tests.cpp
        Utilities.cpp
        Utilities.h
        Matrix.cpp
        Matrix.h
        MataMvidia.h
        MataMvidia.cpp)
