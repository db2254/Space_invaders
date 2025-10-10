#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_parameters.hpp"
#include "game_system.hpp"


// Static variable definitions
sf::Texture GameSystem::spritesheet;
sf::Sprite GameSystem::invader;


void GameSystem::init() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect({ 0, 0 }, { Parameters::sprite_size, Parameters::sprite_size }));


}

void GameSystem::clean() {
}

void GameSystem::update(const float& dt) {
}

void GameSystem::render(sf::RenderWindow& window) {
    window.draw(invader);
}