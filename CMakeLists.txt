cmake_minimum_required(VERSION 3.27)
project(Unik)

set(CMAKE_CXX_STANDARD 17)

add_executable(Unik main.cpp
        class/Object.cpp
        headers/Object.h
        class/Hero.cpp
        headers/Hero.h
        class/Rocket.cpp
        headers/Rocket.h
        class/Engine.cpp
        headers/Engine.h
        class/Game.cpp
        headers/Game.h
        class/GameTxt.cpp
        headers/GameTxt.h)
