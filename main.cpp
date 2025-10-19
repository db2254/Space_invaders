#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_parameters.hpp"
#include "game_system.hpp"


using gs = GameSystem;
using param = Parameters;

int main() {

    sf::RenderWindow window(sf::VideoMode(Parameters::game_width, Parameters::game_height), "Space Invaders");

    gs::init();

    while (window.isOpen()) {
        static sf::Clock clock;
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

   
        window.clear();
        gs::update(dt);
        gs::render(window);
        sf::sleep(sf::seconds(param::time_step));
        //Wait for Vsync
        window.display();
    }
    gs::clean();
    return 0;
}