#include "../headers/GameSFML.h"
#include <iostream>

// Konstruktor
GameSFML::GameSFML() : window(sf::VideoMode(800, 800), "Unik") {
    loadTextures();
}

// Destruktor
GameSFML::~GameSFML() {
}

// Ładowanie tekstur
void GameSFML::loadTextures() {
    if (!heroTexture.loadFromFile("../graphic/hero.png")) {
        std::cerr << "Error loading hero texture" << std::endl;
    }
    if (!rocketTexture.loadFromFile("../graphic/rocket.png")) {
        std::cerr << "Error loading rocket texture" << std::endl;
    }

    heroSprite.setTexture(heroTexture);
    rocketSprite.setTexture(rocketTexture);
}

// Obsługa wejścia
void GameSFML::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
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

// Aktualizacja stanu gry
void GameSFML::update() {
    for (auto &rocket : rockets) {
        rocket.move();
    }

    // Sprawdzenie kolizji
    for (const auto &rocket : rockets) {
        if (rocket.getLocationX() == hero.getLocationX() && rocket.getLocationY() == hero.getLocationY()) {
            std::cout << "Game Over! You were hit by a rocket!" << std::endl;
            //window.close();
        }
    }
}

// Renderowanie gry
void GameSFML::render() {
    window.clear();

    // Rysowanie bohatera
    heroSprite.setPosition(hero.getLocationX() * 80, hero.getLocationY() * 80);
    window.draw(heroSprite);

    // Rysowanie rakiet
    for (const auto &rocket : rockets) {
        rocketSprite.setPosition(rocket.getLocationX() * 80, rocket.getLocationY() * 80);
        window.draw(rocketSprite);
    }

    window.display();
}

// Główna pętla gry
void GameSFML::Run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}

// Pokazywanie stanu gry (nie używane w SFML)
void GameSFML::Show() {
}
