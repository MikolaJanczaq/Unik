cmake_minimum_required(VERSION 3.27)
project(Unik)

set(CMAKE_CXX_STANDARD 17)

add_executable(Unik
        main.cpp
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
        class/GameSFML.cpp
        headers/GameSFML.h
        class/HeroControllerSFML.cpp
        headers/HeroControllerSFML.h
)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

include_directories("C:/SFML/include")

link_directories("C:/SFML/lib")

target_link_libraries(Unik sfml-system sfml-window sfml-graphics sfml-network sfml-audio)