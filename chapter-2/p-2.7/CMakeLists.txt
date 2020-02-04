cmake_minimum_required(VERSION 2.8.3)
project(check-linked-list-intersection)

set(SOURCE "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(${PROJECT_NAME} "${SOURCE}")