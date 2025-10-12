#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "game_parameters.hpp"
#include "game_system.hpp"
#include "ship.hpp"


// Static variable definitions
sf::Texture GameSystem::spritesheet;
sf::Sprite GameSystem::invader;
std::vector<std::shared_ptr<Ship>> GameSystem::ships;


void GameSystem::init() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect({ 0, 0 }, { Parameters::sprite_size, Parameters::sprite_size }));


    std::shared_ptr<Invader> inv = std::make_shared<Invader>(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)), sf::Vector2f{ 100,100 });
    ships.push_back(inv); // This is when the copy instructor is called
}

void GameSystem::clean() {
}

void GameSystem::update(const float& dt) {
    for (std::shared_ptr<Ship>& s : ships) {
        s->update(dt);
    }
}

void GameSystem::render(sf::RenderWindow& window) {
    window.draw(invader);

    for (const std::shared_ptr<Ship>& s : ships) {
        window.draw(*(s.get()));
    }
}