cmake_minimum_required(VERSION 3.10)
project(algorithm VERSION 0.1.0 LANGUAGES CXX)

# Define source directory
set(CORE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/core)

add_executable(algorithm
    ${CORE_DIR}/main.cpp
)