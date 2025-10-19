// game_system.hpp
#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "ship.hpp"

struct GameSystem {

    // Share texture and sprite resources
    static sf::Texture spritesheet;
    static sf::Sprite invader;
    static std::vector<std::shared_ptr<Ship>> ships; // vector of all ship objects both players and invaders

    // Game system functions
    static void init();  // Initialise game resources
    static void clean();  // Clean up game resources 
    static void reset(); 
    static void update(const float& dt);  // Update game state 
    static void render(sf::RenderWindow &window);  // Render game entities
};