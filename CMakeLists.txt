cmake_minimum_required(VERSION 3.17)
project(Encoding C)

set(CMAKE_C_STANDARD 11)

include_directories(source)

add_executable(Encoding
        source/encoded.h
        source/pair.h
        main.c source/encoded.c)
