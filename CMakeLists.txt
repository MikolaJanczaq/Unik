cmake_minimum_required(VERSION 3.27)
project(Unik)

set(CMAKE_CXX_STANDARD 17)

# Dodaj wszystkie pliki źródłowe i nagłówki
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
        class/GameTxt.cpp
        headers/GameTxt.h
        class/GameSFML.cpp
        headers/GameSFML.h
)

set(SFML_STATIC_LIBRARIES TRUE)
# Ustaw ścieżki do bibliotek i nagłówków SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Podaj ścieżkę do katalogu zawierającego nagłówki SFML
include_directories("C:/SFML/include")

# Podaj ścieżkę do katalogu zawierającego biblioteki SFML
link_directories("C:/SFML/lib")

# Powiąż biblioteki SFML
target_link_libraries(Unik sfml-system sfml-window sfml-graphics sfml-network sfml-audio)