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
    void Show() override;
    void MoveInput();

public:
    GameSFML();
    ~GameSFML() override;

    void Run() override;

};

#endif //UNIK_GAMESFML_H