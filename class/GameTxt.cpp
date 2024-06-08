#include "../headers/GameTxt.h"
#include <iostream>

void GameTxt::Show() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (tab[i][j] == 1)
                std::cout << 'H'; // Hero
            else if (tab[i][j] == 2)
                std::cout << 'R'; // Rocket
            else
                std::cout << '.'; // Empty space
        }
        std::cout << std::endl;
    }
}
