#ifndef UNIK_HEROCONTROLLERSFML_H
#define UNIK_HEROCONTROLLERSFML_H

#include "Hero.h"
#include <SFML/Graphics.hpp>

class HeroControllerSFML {
private:
    HeroControllerSFML(const HeroControllerSFML &hc);
    HeroControllerSFML& operator=(const HeroControllerSFML &hc);

    Object* hero;

public:
    HeroControllerSFML(Object* h);
    void handleInput(const sf::Event& event);
};

#endif // UNIK_HEROCONTROLLERSFML_H
