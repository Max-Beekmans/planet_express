cmake_minimum_required(VERSION 3.8)
project(planet_express)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Controller/Headquarters.cpp Controller/Headquarters.h Helper/IOHandler.h Model/Sector.cpp Model/Sector.h Model/SpaceShip.cpp Model/SpaceShip.h Model/Player.cpp Model/Player.h Helper/MyString.cpp Helper/MyString.h Model/SectorTile.cpp Model/SectorTile.h Model/Scan.cpp Model/Scan.h Controller/Game.cpp Controller/Game.h Helper/IOHandler.cpp FileReader/FileHandler.cpp FileReader/FileHandler.h)
add_executable(planet_express ${SOURCE_FILES})