#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "game_parameters.hpp"
#include "game_system.hpp"
#include "ship.hpp"

using param = Parameters;


// Static variable definitions
sf::Texture GameSystem::spritesheet;
sf::Sprite GameSystem::invader;
std::vector<std::shared_ptr<Ship>> GameSystem::ships;


void GameSystem::init() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    reset();
}

void GameSystem::reset() {
    // Clear existing ships if needed
    ships.clear();

    std::shared_ptr<Ship> player = std::make_shared<Player>();
    ships.push_back(player);
    // Create invaders in a grid and add them to ships vector
    for (int r = 0; r < param::rows; ++r) {
        sf::IntRect rect(sf::Vector2i(32 * r, 0), sf::Vector2i(32, 32));
        for (int c = 0; c < param::columns; ++c) {
            sf::Vector2f position(
                c * (param::sprite_size + param::spacing) + param::sprite_size / 2.f,
                r * (param::sprite_size + param::spacing) + param::sprite_size / 2.f
            );
            std::shared_ptr<Invader> inv = std::make_shared<Invader>(rect, position);
            ships.push_back(inv);
        }
    }
}

void GameSystem::clean() {
    for (std::shared_ptr<Ship>& ship : ships)
        ship.reset();//free up the memory of this shared pointer
    ships.clear();//clear the vector to be sure we free up any memory left.
}

void GameSystem::update(const float& dt) {
    for (std::shared_ptr<Ship>& s : ships) {
        s->update(dt);
    }
}

void GameSystem::render(sf::RenderWindow& window) {

    for (const std::shared_ptr<Ship>& s : ships) {
        window.draw(*(s.get()));
    }
}