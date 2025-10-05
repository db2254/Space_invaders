#include <SFML/Graphics.hpp>
#include <iostream>

sf::Texture spritesheet;
sf::Sprite invader;

void init() {
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
}

void render(sf::RenderWindow& window) {
	window.draw(invader);
}

int main() {

    sf::RenderWindow window(sf::VideoMode(400, 250), "Space Invaders");

    init();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

   
        render(window);
        window.display();
    }
}