cmake_minimum_required(VERSION 3.0)
project(helloCMake)

add_executable(helloCMake main.cpp)

add_library(
	hello
	hello.hpp
	hello.cpp
)

target_link_libraries(helloCMake hello)

add_compile_options(-Wall) 

