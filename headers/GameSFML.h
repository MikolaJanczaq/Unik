#ifndef UNIK_GAMESFML_H
#define UNIK_GAMESFML_H

#include "Game.h"
#include "HeroControllerSFML.h"
#include <SFML/Graphics.hpp>

class GameSFML : public Game {
private:
    sf::RenderWindow window;
    sf::Texture heroTexture;
    sf::Texture rocketTexture;
    sf::Sprite heroSprite;
    sf::Sprite rocketSprite;
    HeroControllerSFML heroController;

    void Show() override;

public:
    GameSFML(const char* fn);
    ~GameSFML() override;

    void Run() override;
};

#endif //UNIK_GAMESFML_H