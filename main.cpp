#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_parameters.hpp"
#include "game_system.hpp"



int main() {

    sf::RenderWindow window(sf::VideoMode(Parameters::game_width, Parameters::game_height), "Space Invaders");

    GameSystem::init();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

   
        GameSystem::render(window);
        window.display();
    }
}