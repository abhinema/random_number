# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.0)

# Project's name
project(duplicateInRandomNumbers)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)

# The following folder will be included
include_directories("${INCLUDE_PATH}")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_executable(duplicateInRandomNumbers ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(duplicateInRandomNumbers -lcrypto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcrypto")

