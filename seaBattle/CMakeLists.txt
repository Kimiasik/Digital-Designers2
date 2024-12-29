cmake_minimum_required(VERSION 3.27)
project(seaBattle)

set(CMAKE_CXX_STANDARD 17)

add_executable(seaBattle main.cpp
        battle.h
        battle.cpp
        Map.h
        Map.cpp
        Menu.h
        Menu.cpp
        Game.h
        Game.cpp)
