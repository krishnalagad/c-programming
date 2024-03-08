cmake_minimum_required(VERSION 3.16)
project(testmath)

add_executable(testmath main.cpp)
target_link_directories(testmath PRIVATE ${CMAKE_SOURCE_DIR}/../cpp/build/ )
target_link_libraries(testmath mymath)