cmake_minimum_required(VERSION 3.8)
project(planet_express)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp headquarters.cpp headquarters.h Helper/IOHandler.h sector.cpp sector.h spaceShip.cpp spaceShip.h player.cpp player.h Helper/mString.cpp Helper/mString.h sector_tile.cpp sector_tile.h scan.cpp scan.h game.cpp game.h Helper/IOHandler.cpp)
add_executable(planet_express ${SOURCE_FILES})