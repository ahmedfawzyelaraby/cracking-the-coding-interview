cmake_minimum_required(VERSION 2.8.3)
project(minimum-height-binary-tree)

set(SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_executable(${PROJECT_NAME} "${SOURCE}")