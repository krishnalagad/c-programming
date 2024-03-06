cmake_minimum_required(VERSION 3.15)
project(SimpleCMakeProject)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLE "Whether or nor to build examples: " ON)

if(BUILD_EXAMPLE)
	message(STATUS "Building examples...")
	add_subdirectory(example)
endif()

