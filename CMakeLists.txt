#cmake_minimum_required(VERSION 3.20)
project(clox C)

set(CMAKE_C_STANDARD 99)

add_executable(clox main.c chunk.c compiler.c debug.c memory.c object.c scanner.c value.c vm.c table.c table.h)
#this is comment