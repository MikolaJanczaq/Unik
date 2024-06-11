#ifndef UNIK_HEROCONTROLLERSFML_H
#define UNIK_HEROCONTROLLERSFML_H

#include "Hero.h"
#include <SFML/Graphics.hpp>

class HeroControllerSFML {
private:
    Hero& hero;

public:
    HeroControllerSFML(Hero& h);
    void handleInput(const sf::Event& event);
};

#endif // UNIK_HEROCONTROLLERSFML_H
