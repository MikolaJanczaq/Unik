#include "../headers/HeroControllerSFML.h"

HeroControllerSFML::HeroControllerSFML(Object* h) : hero(h) {}

void HeroControllerSFML::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::W:
                hero->move('w');
                break;
            case sf::Keyboard::A:
                hero->move('a');
                break;
            case sf::Keyboard::S:
                hero->move('s');
                break;
            case sf::Keyboard::D:
                hero->move('d');
                break;
            default:
                break;
        }
    }
}