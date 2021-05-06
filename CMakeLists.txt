cmake_minimum_required(VERSION 3.17)
project(Encoding C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

include_directories(source external)

add_executable(Encoding
        source/encoded.h
        source/pair.h
<<<<<<< HEAD
        main.c source/encoded.c)
=======
        main.c)

add_executable(Encoding-UnitTest
        source/encoded.h
        source/pair.h
        unit-test.cpp)
>>>>>>> 8872fc1121a44026735de9a52ad219682ceb8863
