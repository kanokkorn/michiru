cmake_minimum_required (VERSION 3.10)
project (michiru)

set (CMAKE_C_FLAGS "--std=c17 -O3 -Wall")

add_executable (michiru main.c)

