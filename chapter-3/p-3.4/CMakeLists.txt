cmake_minimum_required(VERSION 2.8.3)
project(queue-of-two-stacks)

set(SOURCE "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(${PROJECT_NAME} "${SOURCE}")