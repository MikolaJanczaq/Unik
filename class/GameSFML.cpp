#include "../headers/GameSFML.h"
#include <iostream>
#include <thread>

GameSFML::GameSFML()
        : window(sf::VideoMode(800, 800), "Game Window") {

    if (!heroTexture.loadFromFile("../graphic/hero.png")) {
        std::cout << "Failed to load hero texture!" << std::endl;
        exit(420);
    }
    heroSprite.setTexture(heroTexture);
    heroSprite.setScale(80.0f / heroTexture.getSize().x, 80.0f / heroTexture.getSize().y);

    if (!rocketTexture.loadFromFile("../graphic/bomb.png")) {
        std::cout << "Failed to load rocket texture!" << std::endl;
        exit(421);
    }
    rocketSprite.setTexture(rocketTexture);
    rocketSprite.setScale(80.0f / rocketTexture.getSize().x, 80.0f / rocketTexture.getSize().y);
}

GameSFML::~GameSFML() {}

void GameSFML::MoveInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::W:
                    hero.move('w');
                    break;
                case sf::Keyboard::A:
                    hero.move('a');
                    break;
                case sf::Keyboard::S:
                    hero.move('s');
                    break;
                case sf::Keyboard::D:
                    hero.move('d');
                    break;
                default:
                    break;
            }
        }
    }
}


void GameSFML::Show() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (tab[i][j] == 1) {
                heroSprite.setPosition(j * 80, i * 80);
                window.draw(heroSprite);
            } else if (tab[i][j] == 2) {
                rocketSprite.setPosition(j * 80, i * 80);
                window.draw(rocketSprite);
            }
        }
    }
}


void GameSFML::Run() {
    gameStatus = true;
    std::thread rocketThread(&Engine::MoveRockets, this);
    rocketThread.detach();


    while (window.isOpen()) {
        if(!gameStatus) {
            std::cout << "Game Over! You were hit by a rocket!" << std::endl;
            exit(0);
        }

        Analysis();
        MoveInput();

        window.clear();
        Show();
        window.display();
    }

}

