#ifndef UNIK_GAMESFML_H
#define UNIK_GAMESFML_H

#include "Game.h"
#include <SFML/Graphics.hpp>

class GameSFML : public Game {
private:
    sf::RenderWindow window;
    sf::Texture heroTexture;
    sf::Texture rocketTexture;
    sf::Sprite heroSprite;
    sf::Sprite rocketSprite;

public:
    GameSFML();
    ~GameSFML();

    void Run() override;
    void Show() override;
};

#endif //UNIK_GAMESFML_H
