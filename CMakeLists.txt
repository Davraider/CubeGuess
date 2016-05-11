cmake_minimum_required(VERSION 3.5)
project(CubeGuess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES main.c playground.c playground.h calculation.c calculation.h)
add_executable(CubeGuess ${SOURCE_FILES} main.c)