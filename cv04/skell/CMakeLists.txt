cmake_minimum_required (VERSION 2.8)

set (CMAKE_C_FLAGS "--std=c99 ${CMAKE_C_FLAGS}")

project (cv04)
add_executable(mystring main.c mystring.c)






