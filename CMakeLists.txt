cmake_minimum_required(VERSION 3.8)
project(planet_express)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Controller/headquarters.cpp Controller/headquarters.h Helper/IOhandler.h Model/sector.cpp Model/sector.h Model/spaceShip.cpp Model/spaceShip.h Model/player.cpp Model/player.h Helper/mString.cpp Helper/mString.h Model/sector_tile.cpp Model/sector_tile.h Model/scan.cpp Model/scan.h Controller/game.cpp Controller/game.h Helper/IOhandler.cpp FileReader/file_handler.cpp FileReader/file_handler.h)
add_executable(planet_express ${SOURCE_FILES})