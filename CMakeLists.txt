cmake_minimum_required(VERSION 3.8)
project(planet_express)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp planet_express.cpp planet_express.h)
add_executable(planet_express ${SOURCE_FILES})