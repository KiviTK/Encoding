cmake_minimum_required(VERSION 3.17)
project(Encoding C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

include_directories(source external)

add_executable(Encoding
        source/encoded.h
        source/encoded.c
        source/pair.h
        main.c)

add_executable(Encoding-UnitTest
        source/encoded.h
        source/encoded.c
        source/pair.h
        external/catch.hpp
        unit-test.cpp)
