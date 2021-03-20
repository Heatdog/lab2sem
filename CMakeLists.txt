cmake_minimum_required(VERSION 3.17)
project(lab2_sem2 C)

set(CMAKE_C_STANDARD 99)


add_definitions(-DUSE_VECTOR)

add_executable(lab2_sem2 main.c input.h input.c vector.h vector.c list.h list.c)

