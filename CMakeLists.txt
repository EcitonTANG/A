cmake_minimum_required(VERSION 3.20)
project(A)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A
        Character.cpp
        Character.h
        Fight.cpp
        Fight.h
        Game.cpp
        Game.h
        Item.cpp
        Item.h
        main.cpp)
