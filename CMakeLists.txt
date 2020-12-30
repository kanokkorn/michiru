cmake_minimum_required (VERSION 3.10)
project (michiru VERSION 0.0.1)

if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
  set (CMAKE_C_FLAGS "--std=c99 -O3 -Wall")
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC") 
  set (CMAKE_C_FLAGS "/std:c11 /O2")
endif()

add_executable (michiru main.c)

