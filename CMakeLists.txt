cmake_minimum_required(VERSION 2.8)
option(build_tests "Build all unit tests")

project(data_structures_and_algorithms)

if(APPLE OR UNIX)
  set(CMAKE_CXX_COMPILER "clang++")
endif()

include_directories(include)

add_definitions(-std=c++11
                -Wall
                -Werror
                -g
                )

add_subdirectory(src)
add_subdirectory(test)
